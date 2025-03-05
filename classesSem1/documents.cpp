#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Documents
{
private:
    vector<string> chapters;

public:
    Documents(vector<string> chapter)
    {
        chapters = chapter;
    }

    void addChapter(string chapter)
    {
        chapters.push_back(chapter);
    }

    void listChapters(int upToLevel)
    {
        int chapterIndex = 1;
        for (int x = 0; x < upToLevel; x++)
        {
            cout << "CHAPTER " << chapterIndex << ": " << chapters.at(x) << "\n";
            chapterIndex++;
        }
    }

    void getNumberOfChapters()
    {
        cout << "Number of Chapters: " << chapters.size() << "\n";
    }

    void removeLastChapter()
    {
        chapters.pop_back();
    }
};

int main()
{
    Documents MilkAndHoney({"the hurting", "the loving", "the breaking", "the healing"});
    MilkAndHoney.addChapter("the conjuring");
    MilkAndHoney.listChapters(5);
    MilkAndHoney.getNumberOfChapters();
    MilkAndHoney.removeLastChapter();
    MilkAndHoney.listChapters(3);
    return 0;
}