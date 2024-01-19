#include "model.h"
#include "interface.h"
#include "defs.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Cell structure
typedef struct
{
    char *text;    // All the cell's text
    double number; // All the cell's numbers
    int varType;   // 1 = number, 0 = text
    char *formula; // Store the formula as a string
    double sum;    // result of formulas
} Cell;

// defining the spreadsheet
static Cell spreadsheet[NUM_ROWS][NUM_COLS];

// Check if a character is a valid identifier
int verifyCellType(char n)
{
    return isalpha(n) || isdigit(n); // Functions that return true if a character is a number or alphabetical
}

// Gets the cell coordinates from the user-inputted formula
void convertToCoordinates(const char *formula, int *row, int *col, int *index)
{
    *col = formula[*index] - 'A';          // Converts letter to column index
    *row = atoi(&formula[*index + 1]) - 1; // Converts substring to row index, courtest of Stackoverflow thread mentioned in the report

    // Continue index after cell coordinates reached
    while (verifyCellType(formula[*index]))
    {
        (*index)++;
    }
}

// Obtain cell sum
double evaluateCell(int row, int col)
{
    if (spreadsheet[row][col].varType)
    {
        return spreadsheet[row][col].number;
    }
    else
    {
        return spreadsheet[row][col].sum;
    }
}

// Perform addition in the formula
double evaluateNumeric(const char *formula, int *index)
{
    char stringResult[15];
    int j = 0;

    // Get the number values in the formula
    while (isdigit(formula[*index]) || formula[*index] == '.' || formula[*index] == '+')
    {
        stringResult[j++] = formula[(*index)++];
    }

    stringResult[j] = '\0';

    // Must convert the string into a double before returning it
    return atof(stringResult);
}

// Evaluate addition formulas containing cell coordinates
double evaluate_formula(const char *formula)
{
    double sum = 0.0;          // total sum
    int len = strlen(formula); // user-inputted string

    // Check if the formula starts with '='
    if (formula[0] == '=')
    {
        // Iterate past '='
        int i = 1;

        // Must traverse through user-input string to calculate the sum
        while (i < len)
        { // If there are coordinates in the formulq
            if (isalpha(formula[i]))
            {
                // Provides cell coordinates and adds value to total sum
                int col, row;
                convertToCoordinates(formula, &row, &col, &i);
                sum += evaluateCell(row, col);
            }
            else if (isdigit(formula[i]) || formula[i] == '+')
            {
                // Complete addition inside formula that does not contain coordinates
                sum += evaluateNumeric(formula, &i);
            }
            else
            {
                i++; // Can ignore irrelevant characters in the formula
            }
        }
    }
    else
    {
        // Formulas not beginnig with '=', are treated as regular string
        sum = atof(formula); // Converts formula string into float value
    }

    return sum; // Return total formula sum
}
// initialize the spreadsheet
void model_init()
{
    // Set all cells to be empty when starting the spreadsheet
    for (int i = 0; i < NUM_ROWS; ++i)
    {
        for (int j = 0; j < NUM_COLS; ++j)
        {
            spreadsheet[i][j].text = NULL;
            spreadsheet[i][j].number = 0.0;
            spreadsheet[i][j].varType = 0;
            spreadsheet[i][j].formula = NULL;
        }
    }
}

// cell value at specific row and column
void set_cell_value(ROW row, COL col, char *text)
{
    // Free any existing values for efficient memory usage
    if (spreadsheet[row][col].text != NULL)
    {
        free(spreadsheet[row][col].text);
    }
    if (spreadsheet[row][col].formula != NULL)
    {
        free(spreadsheet[row][col].formula);
    }

    // Covert any inputed text to a number and check to see if successful
    char *remainingString;
    double number = strtod(text, &remainingString);

    if (*remainingString == '\0' && text[0] != '=')
    {
        // If the input is a number, do the following:
        spreadsheet[row][col].number = number;
        spreadsheet[row][col].varType = 1;
        spreadsheet[row][col].text = strdup(text);
        spreadsheet[row][col].formula = NULL;
        spreadsheet[row][col].sum = 0.0;
    }
    else
    {
        // If the input is not a number, check if it's a formula
        if (text[0] == '=')
        {

            spreadsheet[row][col].text = NULL;
            spreadsheet[row][col].formula = strdup(text + 1);

            // Get the sum
            double sum = evaluate_formula(spreadsheet[row][col].formula);

            // Store the sum in the cell data
            spreadsheet[row][col].sum = sum;
            spreadsheet[row][col].varType = 1; // Indicate that it's a numeric sum
        }
        else
        {
            // If the input is regular text, do the following
            spreadsheet[row][col].text = strdup(text);
            spreadsheet[row][col].formula = NULL;
            spreadsheet[row][col].sum = 0.0;
            spreadsheet[row][col].varType = 0;
        }
    }

    // Update the display
    update_cell_display(row, col, get_textual_value(row, col));
    free(text);
}

// Clear value of cell at specific row and column
void clear_cell(ROW row, COL col)
{

    // Clear memory
    if (spreadsheet[row][col].text != NULL)
    {
        free(spreadsheet[row][col].text);
    }
    if (spreadsheet[row][col].formula != NULL)
    {
        free(spreadsheet[row][col].formula);
    }

    // Set all cell values to 0
    spreadsheet[row][col].text = NULL;
    spreadsheet[row][col].number = 0.0;
    spreadsheet[row][col].varType = 0;
    spreadsheet[row][col].formula = NULL; // Clear formula

    update_cell_display(row, col, "");
}

// Function which provides text value for user to edit
char *get_textual_value(ROW row, COL col)
{
    // Check the whether cell contains number
    if (spreadsheet[row][col].varType)
    {
        // Returns duplicate string if cells exists, returns empty string if not
        return strdup(spreadsheet[row][col].text ? spreadsheet[row][col].text : "");
    }
    // If cell contains formula, evaluate into numerical representation
    else if (spreadsheet[row][col].formula != NULL)
    {
        double sum = evaluate_formula(spreadsheet[row][col].formula);
        char stringResult[15]; // Adjust the size based on the expected maximum length of a numeric value
        sprintf(stringResult, "%f", sum);
        return strdup(stringResult);
    }

    else // If not a formula or number, check for text
    {
        // If there is text, return the duplicated string, if not, return an empty string
        return strdup(spreadsheet[row][col].text ? spreadsheet[row][col].text : "");
    }
}
