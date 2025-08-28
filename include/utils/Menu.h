#include <iostream>
#include <vector>
#include "utils/Graph.h"

/** Function to select an action from the main menu
*
* @return The selected action
*/
int selectAction();

/** Function to run the performance menu
*
* @param g The graph to be used in the performance test
*/
void runPerformanceMenu(Graph& g);

/** Function to select a thread safety data structure
*
* @return The selected data structure
*/
int selectThreadSafetyDataStructure();

/** Function to select a thread safety test type
*
* @return The selected test type
*/
int selectThreadSafetyTestType();

/** Function to run the thread safety menu
*
* @param g The graph to be used in the thread safety tests
*/
void runThreadSafetyMenu();

/** Function to show algorithm descriptions
*
* @param g The graph to be used to initialize the algorithms
*/
void showAlgorithmDescriptions(Graph& g);

