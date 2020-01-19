# -*- coding: utf-8 -*-
from scrapy.crawler import CrawlerProcess
from scrapy.utils.project import get_project_settings

import getopt 
import argparse
import logging

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
    parser.add_argument("-c", "--chain", help="parse and process the archived data", action="store_true")
    parser.add_argument("-p", "--parse", help="parse and process the archived data", action="store_true")
    parser.add_argument("-r", "--run", help="run the spider", action="store_true")
    parser.add_argument("-l", "--plot", help="plot the harvested data", action="store_true")

    # Parse all the arguments
    args = parser.parse_args()

    # Initiate logging
    # FIXME: Needs adjusting
    logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.INFO)
    logging.info('Start application')

    # Print the version
    if args.version:
        print("%s v%d.%d.%d" %(APP_NAME, RELEASE, VERSION, REVISION))
    
    # Run the full chain
    if args.chain:
        run_chain()        

    # Run the spiders
    elif args.run:
        run_spider()        
    
    # Report the archived data
    elif args.parse:
        run_parse()

    # Plot the datasets
    elif args.plot:
        run_plot()

# Functions for options
def run_chain():
    # Run the full chain

    run_spider()
    run_parse()
    run_plot()

def run_spider():
    # Run the dedicated spider

    process = CrawlerProcess(get_project_settings())

    # TODO: To be updated for all the spiders
    process.crawl('psstore_games', domain='')
    process.start() 

def run_parse():
    # Parse the archived data

    arch_handler = ArchHandler()
    arch_handler.parse()

def run_plot():
    # Plot the datasets

    arch_handler = ArchHandler()
    arch_handler.plot()

if __name__ == '__main__' and __package__ is None: 
    from os import sys, path 
    sys.path.append(path.dirname(path.dirname(path.abspath(__file__))))

    # Entry point
    main()