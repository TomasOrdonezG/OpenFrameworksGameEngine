#!/bin/bash
make -j$(nproc) && XDG_SESSION_TYPE=x11 make run
