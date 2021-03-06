/**
 * @file devicesparams.h
 *
 */
/* Copyright (C) 2017-2018 by Arjan van Vught mailto:info@raspberrypi-dmx.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef WS28XXSTRIPEPARAMS_H_
#define WS28XXSTRIPEPARAMS_H_

#include <stdint.h>

#include "ws28xxstripedmx.h"

class WS28XXStripeParams {
public:
	WS28XXStripeParams(void);
	~WS28XXStripeParams(void);

	bool Load(void);

	TWS28XXType GetLedType(void) const;
	uint16_t GetLedCount(void) const;

	void Set(SPISend *);
	void Dump(void);

public:
	static const char *GetLedTypeString(TWS28XXType);

private:
	bool IsMaskSet(uint16_t) const;

public:
    static void staticCallbackFunction(void *p, const char *s);

private:
    void callbackFunction(const char *s);

private:
    uint32_t m_bSetList;
	TWS28XXType tLedType;
	uint16_t nLedCount;
};

#endif /* WS28XXSTRIPEPARAMS_H_ */
