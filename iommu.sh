#!/bin/sh
# List devices and their IOMMU group. Tab-delimited, and sorted by group.
# First number is the group.
# Made by PainSled

pipe="/tmp/iommu_group_and_device_fifo_pipe\
_with_a_name_unlikely_to_be_used_by_others"

rm -f $pipe
mkfifo $pipe

paste <(
	find /sys/kernel/iommu_groups/ -type l |
	awk -F "[/]" '{ printf "%02u\t%s\n", $(NF-2), $NF }' |
	sort |
	tee $pipe
) <(\
	cat $pipe |
	awk -F "[\t]" '{ print $NF }' |
	xargs -L 1 lspci -s |
	sed -u 's/^[^ ]* //'
)

rm $pipe