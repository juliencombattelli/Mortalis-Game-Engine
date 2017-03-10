//============================================================================
// Name        : DPad.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 29 juin 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#ifndef DPAD_HPP_
#define DPAD_HPP_

#include <MGE/Config/ActionConfig.hpp>
#include <map>
#include <list>

namespace mge
{

class DPad
{
public:

    DPad(const std::vector<Action>& directionnalActions);
    DPad(const DPad&) = delete;
    DPad& operator=(const DPad&) = delete;
    ~DPad();

    void update(const std::map<Action, bool>& dKeysState);

    bool isSelected(Action action) const;

private:

    struct DKeyState
    {
        bool wasPressed;
        bool isPressed;
        int priority;
    };

    DKeyState* findHighestPriority();
    void adjustPriority();
    void enableHighestPriorityKey();

    std::map<Action, DKeyState> m_DKeys;
};

} // namespace mge

#endif // DPAD_HPP_
