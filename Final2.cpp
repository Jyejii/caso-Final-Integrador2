#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct ColorConsole {
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox {
    void new_text() { /*...*/ }
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox* consoleBox = new ConsoleBox;

void load_script(const char* filename, bool show_script = false) {
    string script;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    try {
        string line;
        while (getline(file, line)) {
            script += line + "\n";
        }

        if (show_script) {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (const exception &e) {
        cerr << "Error while reading file: " << e.what() << endl;
    }
    file.close();
}

int main() {

    load_script("C:\\Users\\jiach\\OneDrive\\Documentos\\GitHub\\caso-Final-Integrador2\\CasoFinalIntegrador 2.txt", true);
    delete consoleBox;


    return 0;
}





