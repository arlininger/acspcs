#!/bin/bash

for i in `seq 3 27`;
do
	squares $i > $i.results &
done


