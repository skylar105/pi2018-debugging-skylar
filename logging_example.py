#!/usr/bin/env python

import argparse
import logging

def get_args():
    """Returns a argparse ArgumentParser instance"""
    parser = argparse.ArgumentParser()
    parser.add_argument('--loglevel',help='Set the logging level to DEBUG|INFO|WARNING|ERROR|CRITICAL (default CRITICAL)')

    return parser.parse_args()

def main():
    args = get_args()

    if args.loglevel is not None:
        loglevel = args.loglevel
    else:
        loglevel = logging.CRITICAL

    logging.basicConfig(
            datefmt='%Y-%m-%dT%H:%M:%S%z',
            format='%(asctime)s %(message)s',
            level=loglevel
            )

    logging.debug('DEBUG test')
    logging.info('INFO test')
    logging.warning('WARNING test')
    logging.error('ERROR test')

if __name__ == '__main__':
    main()
