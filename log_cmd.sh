#!/usr/bin/env bash

set -eo pipefail

# Outputs the current date and time in ISO 8601 format
function date_iso8601() {
	date '+%Y-%m-%dT%H:%M:%S%z'
}

# Outputs a timestamp and a command to STDERR, and runs the command
# Takes advantage of variables being globally scoped by default in shell
function run_cmd() {
	echo "$(date_iso8601),run_cmd,${CMD}" >&2
	${CMD}
}

CMD="/bin/ls ${HOME}"
run_cmd
