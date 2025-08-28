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

/** Function to select a thread safety test type for Stack and later run it
*
* @param dsType The selected data structure type
*/
void selectStackThreadSafetyTestType();

/** Function to select a thread safety test type for Queue and later run it
*
* @param dsType The selected data structure type
*/
void selectQueueThreadSafetyTestType();

/** Function to select a thread safety test type for Priority and later run it
*
* @param dsType The selected data structure type
*/
void selectPriorityThreadSafetyTestType();

/** Function to run Stack thread safety tests
*
* @param dsType The selected data structure type
* @param testType The selected test type
*/
void runStackThreadSafetyTest(int dsType, int testType);

/** Function to run Queue thread safety tests
*
* @param dsType The selected data structure type
* @param testType The selected test type
*/
void runQueueThreadSafetyTest(int dsType, int testType);

/** Function to run Priority thread safety tests
*
* @param dsType The selected data structure type
* @param testType The selected test type
*/
void runPriorityQueueThreadSafetyTest(int dsType, int testType);

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

/** Function to show example algorithm runs
*
* @param g The graph to be used to initialize the algorithms
*/
void showExampleAlgorithmRuns(Graph& g);
