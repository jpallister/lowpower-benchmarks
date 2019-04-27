/* -*- mode: C++; c-file-style: "gnu-mode" -*- */
/* BEEBS qrduino benchmark

   Copyright (C) 2013 Embecosm Limited and University of Bristol

   Contributor James Pallister <james.pallister@bristol.ac.uk>

   This file is part of the Bristol/Embecosm Embedded Benchmark Suite.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <http://www.gnu.org/licenses/>. */

#include "support.h"
#include "qrencode.h"

#include <string.h>

/* This scale factor will be changed to equalise the runtime of the
   benchmarks. */
#define LOCAL_SCALE_FACTOR 6

/* BEEBS heap is just an array */

#define HEAP_SIZE 8192
static char heap[HEAP_SIZE];

static const char *encode;
static int size;

int
benchmark (void)
{
  static const char *in_encode = "http://www.mageec.com";
  int  i;

  for (i = 0; i < (LOCAL_SCALE_FACTOR * REPEAT_FACTOR); i++)
      {
	  encode = in_encode;
	  size = 22;
	  init_heap_beebs ((void *) heap, HEAP_SIZE);

	  initeccsize(1, size);

	  memcpy(strinbuf, encode, size);

	  initframe();
	  qrencode();
	  freeframe();
	  freeecc();
      }

  return 0;
}

void initialise_benchmark() {
}

int verify_benchmark(int unused) {
  unsigned char expected[22] = {
      254, 101,  63, 128, 130, 110, 160, 128, 186,  65,  46,
      128, 186,  38,  46, 128, 186,   9, 174, 128, 130,  20
  };

  return (0 == memcmp (strinbuf, expected, 22 * sizeof (strinbuf[0])))
      && check_heap_beebs ((void *) heap);
}
