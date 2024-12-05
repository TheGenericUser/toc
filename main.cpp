#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class FiniteAutomaton
{
private:
public:
    unordered_map<int, unordered_map<char, int>> transitions;
    int initialState;
    unordered_set<int> finalStates;
    FiniteAutomaton() : initialState(-1) {}

    void setInitialState(int state)
    {
        initialState = state;
    }

    void addTransition(int fromState, char input, int toState)
    {
        transitions[fromState][input] = toState;
    }

    void addFinalState(int state)
    {
        finalStates.insert(state);
    }

    bool isAccepted(const string &input) const
    {
        if (initialState == -1)
        {
            cerr << "Initial state is not set." << endl;
            return false;
        }

        int currentState = initialState;

        for (char c : input)
        {
            if (transitions.at(currentState).find(c) == transitions.at(currentState).end())
                return false; // Transition not defined for current state and input symbol

            currentState = transitions.at(currentState).at(c);
        }

        return finalStates.find(currentState) != finalStates.end();
    }
};

// FA1: Accepts strings with three consecutive 1's
void runFA1()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2, q3 = 3;

    fa.setInitialState(q0);
    fa.addTransition(q0, '0', q0);
    fa.addTransition(q0, '1', q1);
    fa.addTransition(q1, '0', q0);
    fa.addTransition(q1, '1', q2);
    fa.addTransition(q2, '0', q0);
    fa.addTransition(q2, '1', q3);
    fa.addTransition(q3, '0', q3);
    fa.addTransition(q3, '1', q3);
    fa.addFinalState(q3);

    string input;
    cout << "Enter input string for FA1 that accepts strings with three consecutive 1's: ";
    cin >> input;

    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}

// FA2: Accepts strings with exactly two or three 1's
void runFA2()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2, q3 = 3, q4 = 4;

    fa.setInitialState(q0);
    fa.addTransition(q0, '0', q0);
    fa.addTransition(q0, '1', q1);
    fa.addTransition(q1, '0', q1);
    fa.addTransition(q1, '1', q2);
    fa.addTransition(q2, '0', q2);
    fa.addTransition(q2, '1', q3);
    fa.addTransition(q3, '0', q3);
    fa.addTransition(q3, '1', q4);
    fa.addTransition(q4, '0', q4);
    fa.addTransition(q4, '1', q4);
    fa.addFinalState(q2);
    fa.addFinalState(q3);

    string input;
    cout << "Enter input string for FA2 that accepts strings with exactly two or three 1's (Interpretation 1: Not consecutive)";
    cin >> input;

    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}
void runFA3()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2, q3 = 3, q4 = 4;

    fa.setInitialState(q0);
    fa.addTransition(q0, '0', q0);
    fa.addTransition(q0, '1', q1);
    fa.addTransition(q1, '0', q4);
    fa.addTransition(q1, '1', q2);
    fa.addTransition(q2, '0', q4);
    fa.addTransition(q2, '1', q3);
    fa.addTransition(q3, '0', q3);
    fa.addTransition(q3, '1', q4);
    fa.addTransition(q4, '0', q4);
    fa.addTransition(q4, '1', q4);
    fa.addFinalState(q2);
    fa.addFinalState(q3);

    string input;
    cout << "Enter input string for FA2 that accepts strings with exactly two or three 1's (Interpretation 2: consecutive)";
    cin >> input;

    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}

// FA3: Accepts strings of length 4 or more with the first two characters the same as the last two
void runFA4()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2, q3 = 3, q4 = 4, q5 = 5, q6 = 6, q7 = 7, q8 = 8, q9 = 9, q10 = 10, q11 = 11, q12 = 12, q13 = 13, q14 = 14;

    fa.setInitialState(q0);

    fa.addTransition(q0, 'a', q1);
    fa.addTransition(q0, 'b', q8);
    fa.addTransition(q1, 'a', q2);
    fa.addTransition(q1, 'b', q5);
    fa.addTransition(q2, 'a', q3);
    fa.addTransition(q2, 'b', q2);
    fa.addTransition(q3, 'a', q4);
    fa.addTransition(q3, 'b', q2);
    fa.addTransition(q4, 'a', q4);
    fa.addTransition(q4, 'b', q2);
    fa.addTransition(q5, 'a', q6);
    fa.addTransition(q5, 'b', q5);
    fa.addTransition(q6, 'a', q6);
    fa.addTransition(q6, 'b', q7);
    fa.addTransition(q7, 'a', q6);
    fa.addTransition(q7, 'b', q5);
    fa.addTransition(q8, 'a', q9);
    fa.addTransition(q8, 'b', q12);
    fa.addTransition(q9, 'a', q9);
    fa.addTransition(q9, 'b', q10);
    fa.addTransition(q10, 'a', q11);
    fa.addTransition(q10, 'b', q10);
    fa.addTransition(q11, 'a', q9);
    fa.addTransition(q11, 'b', q10);
    fa.addTransition(q12, 'a', q12);
    fa.addTransition(q12, 'b', q13);
    fa.addTransition(q13, 'a', q12);
    fa.addTransition(q13, 'b', q14);
    fa.addTransition(q14, 'a', q12);
    fa.addTransition(q14, 'b', q14);

    fa.addFinalState(q4);
    fa.addFinalState(q7);
    fa.addFinalState(q11);
    fa.addFinalState(q14);

    string input;
    cout << "Enter input string for FA3: ";
    cin >> input;

    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}

// FA4: Accepts strings where the language is a(a+b)*b
void runFA5()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2;

    fa.setInitialState(q0);
    fa.addTransition(q0, 'a', q1);
    fa.addTransition(q1, 'a', q1);
    fa.addTransition(q1, 'b', q2);
    fa.addTransition(q1, 'a', q1);
    fa.addTransition(q2, 'a', q1);
    fa.addTransition(q2, 'b', q2);
    fa.addFinalState(q2);

    string input;
    cout << "Enter input string for FA4: ";
    cin >> input;

    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}

// FA5: Accepts strings for EVEN-EVEN
void runFA6()
{
    FiniteAutomaton fa;

    const int q0 = 0; // even a, even b
    const int q1 = 1; // even a, odd b
    const int q2 = 2; // odd a, even b
    const int q3 = 3; // odd a, odd b

    fa.setInitialState(q0);

    fa.addTransition(q0, 'a', q2);
    fa.addTransition(q0, 'b', q1);
    fa.addTransition(q1, 'a', q3);
    fa.addTransition(q1, 'b', q0);
    fa.addTransition(q2, 'a', q0);
    fa.addTransition(q2, 'b', q3);
    fa.addTransition(q3, 'a', q1);
    fa.addTransition(q3, 'b', q2);

    fa.addFinalState(q0);
    string input;
    cout << "Enter input string for FA5: ";
    cin >> input;
    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}

int main()
{
    int choice;
    cout << "Menu: ";
    // write all the FA'5 definiton
    cout << "\n1. FA1: Accepts strings with three consecutive 1's" << endl;
    cout << "2. FA2: Accepts strings with exactly two or three 1's (Interpretation 1: Not consecutive)" << endl;
    cout << "3. FA2: Accepts strings with exactly two or three 1's (Interpretation 2: consecutive)" << endl;
    cout << "4. FA3: Accepts strings of length 4 or more with the first two characters the same as the last two" << endl;
    cout << "5. FA4: Accepts strings where the language is a(a+b)*b" << endl;
    cout << "6. FA5: Accepts strings for EVEN-EVEN" << endl;
    cout << "Choose Finite Automaton to run (1-6): ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        runFA1();
        break;
    case 2:
        runFA2();
        break;
    case 3:
        runFA3();
        break;
    case 4:
        runFA4();
        break;
    case 5:
        runFA5();
        break;
    case 6:
        runFA6();
        break;
    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}


//6
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class FiniteAutomaton
{
public:
    unordered_map<int, unordered_map<char, int>> transitions;
    int initialState;
    unordered_set<int> finalStates;

    FiniteAutomaton() : initialState(-1) {}

    void setInitialState(int state)
    {
        initialState = state;
    }

    void addTransition(int fromState, char input, int toState)
    {
        transitions[fromState][input] = toState;
    }

    void addFinalState(int state)
    {
        finalStates.insert(state);
    }

    bool isAccepted(const string &input) const
    {
        if (initialState == -1)
        {
            cerr << "Initial state is not set." << endl;
            return false;
        }

        int currentState = initialState;

        for (char c : input)
        {
            if (transitions.at(currentState).find(c) == transitions.at(currentState).end())
                return false; // Transition not defined for current state and input symbol

            currentState = transitions.at(currentState).at(c);
        }

        return finalStates.find(currentState) != finalStates.end();
    }
};

// Helper function to combine two sets
unordered_set<int> combineSets(const unordered_set<int> &set1, const unordered_set<int> &set2)
{
    unordered_set<int> resultSet = set1;
    resultSet.insert(set2.begin(), set2.end());
    return resultSet;
}

// Helper function to create a new state for a pair of states from two FAs
int createStatePair(int state1, int state2, int numStates2)
{
    return state1 * numStates2 + state2;
}

// Union of two finite automata
FiniteAutomaton unionFA(const FiniteAutomaton &fa1, const FiniteAutomaton &fa2)
{
    FiniteAutomaton resultFA;
    int numStates2 = fa2.transitions.size();

    // Set initial state
    resultFA.setInitialState(createStatePair(fa1.initialState, fa2.initialState, numStates2));

    // Combine transitions
    for (const auto &[state1, trans1] : fa1.transitions)
    {
        for (const auto &[state2, trans2] : fa2.transitions)
        {
            for (const auto &[input, nextState1] : trans1)
            {
                int nextState2 = trans2.at(input);
                resultFA.addTransition(createStatePair(state1, state2, numStates2), input, createStatePair(nextState1, nextState2, numStates2));
            }
        }
    }

    // Combine final states
    for (int finalState1 : fa1.finalStates)
    {
        for (int finalState2 : fa2.finalStates)
        {
            resultFA.addFinalState(createStatePair(finalState1, finalState2, numStates2));
        }
    }

    return resultFA;
}

// Intersection of two finite automata
FiniteAutomaton intersectionFA(const FiniteAutomaton &fa1, const FiniteAutomaton &fa2)
{
    FiniteAutomaton resultFA;
    int numStates2 = fa2.transitions.size();

    // Set initial state
    resultFA.setInitialState(createStatePair(fa1.initialState, fa2.initialState, numStates2));

    // Combine transitions
    for (const auto &[state1, trans1] : fa1.transitions)
    {
        for (const auto &[state2, trans2] : fa2.transitions)
        {
            for (const auto &[input, nextState1] : trans1)
            {
                int nextState2 = trans2.at(input);
                resultFA.addTransition(createStatePair(state1, state2, numStates2), input, createStatePair(nextState1, nextState2, numStates2));
            }
        }
    }

    // Combine final states
    for (int finalState1 : fa1.finalStates)
    {
        for (int finalState2 : fa2.finalStates)
        {
            resultFA.addFinalState(createStatePair(finalState1, finalState2, numStates2));
        }
    }

    return resultFA;
}

// Concatenation of two finite automata
FiniteAutomaton concatenateFA(const FiniteAutomaton &fa1, const FiniteAutomaton &fa2)
{
    FiniteAutomaton resultFA;
    int offset = fa1.transitions.size();

    // Copy transitions from fa1
    resultFA.transitions = fa1.transitions;
    resultFA.setInitialState(fa1.initialState);
    resultFA.finalStates = fa2.finalStates;

    // Add transitions from fa2 with offset
    for (const auto &[state, trans] : fa2.transitions)
    {
        for (const auto &[input, nextState] : trans)
        {
            resultFA.addTransition(state + offset, input, nextState + offset);
        }
    }

    // Add transitions for concatenation
    for (int finalState1 : fa1.finalStates)
    {
        resultFA.addTransition(finalState1, 'e', fa2.initialState + offset); // 'e' for epsilon transition
    }

    return resultFA;
}

// Example FA1: Automaton for strings starting with 'a'
FiniteAutomaton createFA1()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2;

    fa.setInitialState(q0);
    fa.addTransition(q0, 'a', q1);
    fa.addTransition(q1, 'a', q1);
    fa.addTransition(q1, 'b', q1);
    fa.addFinalState(q1);

    return fa;
}

// Example FA2: Automaton for strings ending with 'b'
FiniteAutomaton createFA2()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1;

    fa.setInitialState(q0);
    fa.addTransition(q0, 'a', q0);
    fa.addTransition(q0, 'b', q1);
    fa.addTransition(q1, 'a', q0);
    fa.addTransition(q1, 'b', q1);
    fa.addFinalState(q1);

    return fa;
}

int main()
{
    FiniteAutomaton fa1 = createFA1();
    FiniteAutomaton fa2 = createFA2();

    FiniteAutomaton unionResult = unionFA(fa1, fa2);
    FiniteAutomaton intersectionResult = intersectionFA(fa1, fa2);
    FiniteAutomaton concatenationResult = concatenateFA(fa1, fa2);

    string input;
    cout << "Enter input string: ";
    cin >> input;

    cout << "Union FA: " << (unionResult.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
    cout << "Intersection FA: " << (intersectionResult.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
    cout << "Concatenation FA: " << (concatenationResult.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;

    return 0;
}
