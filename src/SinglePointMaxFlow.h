#ifndef PROJECT_RAILWAY_SINGLEPOINTMAXFLOW_H
#define PROJECT_RAILWAY_SINGLEPOINTMAXFLOW_H


#include "MenuItem.h"

class SinglePointMaxFlow : public MenuItem{
private:
    int currMenuPage;
public:
    SinglePointMaxFlow(int &currMenuPage, Graph &gh);
    void execute() override;
};


#endif //PROJECT_RAILWAY_SINGLEPOINTMAXFLOW_H
