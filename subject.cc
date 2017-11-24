#include "subject.h"
#include "commandinfo.h"

void Subject::notifyObservers(const CommandInfo &c) {
    for (const auto observer: observers) {
        observer->update(c);
    }
}
