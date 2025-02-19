#include <iostream>
#include <unordered_set>
#include <sstream>
#include <cctype>
using namespace std;

// Функція для перетворення слова в нижній регістр
string toLower(const string& str) {
    string result;
    for (char ch : str) {
        result += tolower(ch);
    }
    return result;
}

// Функція для очищення слова від знаків пунктуації
string cleanWord(const string& word) {
    string result;
    for (char ch : word) {
        if (isalnum(ch)) { // Враховуємо і букви, і цифри
            result += tolower(ch);
        }
    }
    return result;
}

int main() {
    int N, M;
    cin >> N >> M;
    cin.ignore();
    
    unordered_set<string> dictionary;
    unordered_set<string> usedWords;
    
    for (int i = 0; i < N; i++) {
        string word;
        getline(cin, word);
        dictionary.insert(toLower(word));
    }
    
    bool unknownWordFound = false;
    string line;
    
    for (int i = 0; i < M; i++) {
        getline(cin, line);
        stringstream ss(line);
        string word;
        
        while (ss >> word) {
            word = cleanWord(word);
            if (!word.empty()) {
                if (dictionary.find(word) == dictionary.end()) {
                    unknownWordFound = true;
                }
                usedWords.insert(word);
            }
        }
    }
    
    bool allWordsUsed = true;
    for (const string& word : dictionary) {
        if (usedWords.find(word) == usedWords.end()) {
            allWordsUsed = false;
            break;
        }
    }
    
    if (!unknownWordFound && allWordsUsed) {
        cout << "Everything is going to be OK." << endl;
    } else if (unknownWordFound) {
        cout << "Some words from the text are unknown." << endl;
    } else {
        cout << "The usage of the vocabulary is not perfect." << endl;
    }
    
    return 0;
}