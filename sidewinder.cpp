#include "sidewinder.h"
#include <vector>
#include <cstdlib>

void SideWinder::MazeGenerator(Grid *grid)
{
    std::vector<std::vector<Cell*>> localGrid = grid->returnGrid();
    

    for (auto& row : localGrid) {
        std::vector<Cell*> run;

        for (auto& cell : row) {
            run.push_back(cell);

            bool atEasternBoundary = (cell->getEast() == nullptr);
            bool atNorthernBoundary = (cell->getNorth() == nullptr);

            bool shouldCloseOut = atEasternBoundary || (!atNorthernBoundary && rand() % 2 == 0);

            if (shouldCloseOut) {
                Cell* member = run[rand() % run.size()];
                if (member->getNorth()) {
                    member->setLink(member->getNorth());
                }
                run.clear();
            } else {
                cell->setLink(cell->getEast());
            }

        }
    }
}