#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class DocumentElement {
    public:
        virtual string render() = 0;
};

class TextElement : public DocumentElement {
    private:
        string text;

    public:
        TextElement(string text){
            this -> text = text;
        }

        string render() override {
            return text;
        }
};

class ImageElement : public DocumentElement {
    private:
        string imgPath;

    public:
        ImageElement(string imgPath){
            this -> imgPath = imgPath;
        }

        string render() override {
            return "[Image: "+ imgPath + "]";
        }
};

class NewLineElement : public DocumentElement {
    public:
        string render() override {
            return "/t";
        }
};

class Document {
    private:
        vector<DocumentElement*> documentElements;

    public:
        void addElement (DocumentElement* element){
            documentElements.push_back(element);
        }

        string render() {
            string result;
            for(auto ele : documentElements){
                result += ele -> render();
            }
            return result;
        }
};

class Persistence {
    public:
        virtual void save(string data) = 0;
};

class FileStorage : public Persistence {
    public:
        void save(string data) override {
            ofstream file("document.txt");
            if(outFile){
                outFile << data;
                outFile.close();
                cout << "Document saved to document.txt" << endl;
            }else{
                cout << "Error : Unable to open for writing. " << endl;
            }
        }
};

class DBStorage : public persistence {
    public:
        void save(string data) override {
            cout << "Document saved to DB" << endl;
        }
};

