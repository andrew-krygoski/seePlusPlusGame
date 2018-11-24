#pragma once
class EventTrigger
{
public:
    EventTrigger();
    ~EventTrigger();

protected:
    sf::Event eventTrigger;

};

static enum TriggerEffect { Create, Destroy, ChangeScene };

/*
//Event Trigger JSON
{
//first are all the object effected and what the coressponding effect it
//basically List of GameObjectType's containing a list of GUID's with corressponding
//TriggerEvents to tell us what we're doing with it
"objectsEffected": { GameObjectType: { GameObjectGUID: TriggerEvent} },
"triggerGUID": GUID
}
*/