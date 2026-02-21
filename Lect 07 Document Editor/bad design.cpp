#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Document {
    private:
        vector<string> documentElements;
        string renderElement;
    
    public:
        
        void addText(string text){
            documentElements.push_back(text);
        }

        void addImg(string imgPath){
            documentElements.push_back(imgPath);
        }

        string renderDocument() {
            if(renderedDocument.empty()) {
                string result;
                for (auto element : documentElements) {
                    if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" ||
                    element.substr(element.size() - 4) == ".png")) {
                        result += "[Image: " + element + "]" + "\n";
                } else {
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }

    void saveTofile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file << renderDocument();
            file.close();
            cout << "Document saved to file" << endl;
        }else{
            cout << "Error: Could not open file for writing" << endl;
        }
    }
};

int main() {
    Document editor;
    editor.addText("Hello World");
    editor.addImg("image.jpg");
    editor.saveTofile();
    return 0;
}