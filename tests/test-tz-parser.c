/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Derick Rethans
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "timelib.h"

int main(int argc, char *argv[])
{
	signed long long ts;
	timelib_time *local_time;
	timelib_tzinfo *tz;

	ts = 368237; /*Monday 1970-01-01 17:17:17 */

	tz = timelib_parse_tzfile(argv[1], timelib_builtin_db());
	timelib_dump_tzinfo(tz);

	local_time = timelib_time_ctor();
	timelib_set_timezone(local_time, tz);
	timelib_unixtime2gmt(local_time, ts);
	timelib_dump_date(local_time, 1);
	timelib_unixtime2local(local_time, ts);
	timelib_dump_date(local_time, 1);

	timelib_update_ts(local_time, tz);

	timelib_tzinfo_dtor(local_time->tz_info);
	timelib_time_dtor(local_time);

	return 0;
}
