#include <iostream>

using namespace std;

class IPLAnalyserView {
private:
    public:
    IPLAnalyserView() {}

    void displayWelcomeMessage();
};

void IPLAnalyserView::displayWelcomeMessage() {
    cout << "Welcome To IPL Analyser" << endl;
}