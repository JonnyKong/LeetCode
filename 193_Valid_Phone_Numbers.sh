#!/bin/bash
cat file.txt | grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$'