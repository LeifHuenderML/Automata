#include "interface.hpp"


std::vector<int> Interface::predict(std::vector<std::vector<bool>> &state){
    writeState(state);
    pythonInterface();
    return getPredictions();
}

std::vector<std::vector<bool>> Interface::generateState(){
    srand(time(NULL)); 
    std::vector<std::vector<bool>>  state;
    for (int i = 0; i < 1024; i++) {
        std::vector<bool> row;
        for (int j = 0; j < 1024; j++) {
            row.push_back(rand() % 2);
        }
        state.push_back(row);
    }
    return state;
}

void Interface::writeState(std::vector<std::vector<bool>> &state){
    std::ofstream stateFile(stateFilename);
    if (!stateFile) {
        std::cerr << "Error opening file for output: " << stateFilename << std::endl;

    }
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) {
            if (j < 1023)
                stateFile << state[i][j] << ",";
            else
                stateFile << state[i][j];
        }
        stateFile << "\n";
    }
    stateFile.close();
}

std::vector<int> Interface::getPredictions(){
    std::ifstream predictionFile(predictionFilename);
    std::vector<int> predictions;
    if (!predictionFile) {
        std::cerr << "Error opening file for input: " << predictionFilename << std::endl;
    }
    std::string prediction;
    for(std::string line; getline(predictionFile, line);)
        predictions.push_back(std::stod(line)*100);
    predictionFile.close();
    return predictions;
}

void Interface::printPredictions(std::vector<int> &predictions){
    for(int i = 0; i < predictions.size(); i++)
        std::cout << predictions[i] << " ";
}

void Interface::pythonInterface(){
    std::string command = "python3 rlEngine/interface.py " + stateFilename + " " + predictionFilename;
    system(command.c_str());
}



void Interface::test(){
    std::vector<std::vector<bool>>state = generateState();
    writeState(state);
    pythonInterface();
    std::vector<int> predictions = getPredictions();
    printPredictions(predictions);
    std::cout<<"Test Passed\n";
}