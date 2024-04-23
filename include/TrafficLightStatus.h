#pragma once

#ifndef _TRAFFICLIGHTSTATUS_H_
#define _TRAFFICLIGHTSTATUS_H_

typedef enum {
    TL_GREEN    = 0,
    TL_RED      = 1,
    TL_YELLOW   = 2,
    TL_PREPARE  = 3
} TL_STATUS;

#endif /* _TRAFFICLIGHTSTATUS_H_ */