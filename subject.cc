#include "subject.h"
#include "commandInfo.h"

void Subject::notifyObservers(const CommandInfo &c) {
    for (const auto &observer: observers) {
        observer->update(c);
    }
}

void Subject::attach(std::unique_ptr<Observer> obs) {
    observers.push_back(std::move(obs));
}
