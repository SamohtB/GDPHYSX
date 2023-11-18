#include "EventBroadcaster.h"

using namespace gamecore;


void EventBroadcaster::RegisterListener(EventListener* listener)
{
    EventKey key = listener->GetKey();
    this->mapListener[key].push_back(listener);
    this->vecListener.push_back(listener);
}

void EventBroadcaster::UnregisterListener(EventListener* listener)
{
    EventKey eventKey = listener->GetKey();
    std::vector<EventListener*> vecListener = this->mapListener[eventKey];
    int nIndex = this->FindListener(listener, vecListener);

    delete this->mapListener[eventKey][nIndex];
    this->mapListener[eventKey].erase(this->mapListener[eventKey].begin() + nIndex);

    nIndex = this->FindListener(listener);
    if(nIndex != -1) {
        delete this->vecListener[nIndex];
        this->vecListener.erase(this->vecListener.begin() + nIndex);
    }
}

void EventBroadcaster::UnregisterAllListeners()
{
    for(EventListener* pListener : this->vecListener)
        this->UnregisterListener(pListener);

    this->vecListener.clear();
    this->mapListener.clear();
}

void EventBroadcaster::Broadcast(EventKey key, std::unordered_map<std::string, void*> mapParameter)
{
    for(int i = 0; i < this->mapListener[key].size(); i++) {
        this->mapListener[key][i]->OnEventTrigger(mapParameter);
    }
}

int EventBroadcaster::FindListener(EventListener* pListener, std::vector<EventListener*> vecListener) {
    if(vecListener.empty())
    {
	    vecListener = this->vecListener;
    }

    int nIndex = -1;

    for(int i = 0; i < vecListener.size() && nIndex == -1; i++) 
    {
        if(vecListener[i] == pListener)
            nIndex = i;
    }

    return nIndex;
}

/* * * * * * * * * * * * * * * * * * * * *
 *       SINGLETON-RELATED CONTENT       *
 * * * * * * * * * * * * * * * * * * * * */
EventBroadcaster* EventBroadcaster::Instance = nullptr;

EventBroadcaster* EventBroadcaster::GetInstance() {
    if(Instance == nullptr)
        Instance = new EventBroadcaster();

    return Instance;
}
/* * * * * * * * * * * * * * * * * * * * */
