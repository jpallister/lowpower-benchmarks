# Makefile.am for building a BEEBS benchmark
#
# Copyright (C) 2014 Embecosm Limited and University of Bristol
#
# This file is part of the Bristol/Embecosm Embedded Benchmark Suite.
#
# Contributor: Pierre Langlois <pierre.langlois@embecosm.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# SPDX-License-Identifier: GPL-3.0-or-later

if ENABLED_BENCHMARK_NETTLE_CAST128

include $(top_srcdir)/src/common.mk.am

bin_PROGRAMS                 = nettle-cast128
noinst_LTLIBRARIES           = libnettle-cast128.la

nettle_cast128_SOURCES       =
libnettle_cast128_la_SOURCES = cast128.c

nettle_cast128_LDADD         = $(DUMMY_CRT0) \
                               $(top_builddir)/support/libsupport.la \
                               libnettle-cast128.la \
                               $(DUMMY_LIBC) $(DUMMY_LIBGCC) $(DUMMY_COMPILERRT)


endif
