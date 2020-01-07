# -*- coding: utf-8 -*-
from scrapy.crawler import CrawlerProcess
from scrapy.utils.project import get_project_settings

import getopt 
import argparse

from settings import * 
from items import *
from arch_handler import *

def main():

    # Get all cmd line args
    args_list = sys.argv[1:]

    unix_opts = "ho:v"
    gnu_opts = ["help", "output=", "verbose"]

    # Define the program description
    text = 'This is the entry point of the PSN webscraper.'

    # Initiate the parser with a description
    parser = argparse.ArgumentParser(description = text)
    parser.add_argument("-v", "--version", help="show program version", action="store_true")
    parser.add_argument("-p", "--parse", help="parse and process the archived data", action="store_true")
    parser.add_argument("-r", "--report", help="run the PSN spider", action="store_true")

    args = parser.parse_args()

    # Print the version
    if args.version:
        print("%s v%d.%d.%d" %(APP_NAME, RELEASE, VERSION, REVISION))
    
    # Report the archived data
    elif args.report:
        arch_handler = ArchHandler()
        arch_handler.parse()

    # Run the spiders
    elif args.run:
        process = CrawlerProcess(get_project_settings())

        # TODO: To be updated for all the spiders
        process.crawl('psstore_games', domain='')
        process.start() 

if __name__ == '__main__' and __package__ is None: 
    from os import sys, path 
    sys.path.append(path.dirname(path.dirname(path.abspath(__file__))))

    main()