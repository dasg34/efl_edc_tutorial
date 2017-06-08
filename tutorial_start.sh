#!/bin/bash

gcc tutorial.c -o tutorial `pkg-config --cflags --libs elementary`

edje_cc tutorial*.edc

./tutorial 'tutorial_'$1'.edj'
