# -*- coding: utf-8 -*-
import sys
import os
import csv

from settings import *

class ArchHandler:

    # Private attributes
    _file = None
    _file_path = ARCH_PATH

    def parse(self):
        # Parse every archived file

        games_dict = {}

        # Create data dir if not present
        if not os.path.exists(DATA_PATH):
            os.makedirs(DATA_PATH)

        # Process the archive
        for file in os.listdir(ARCH_PATH):
                
            # Get file attributes
            file_date = file.split('_')[0]
            file_name = os.path.join(ARCH_PATH, file)

            # Open the archive file
            fd = open(file_name, "r")

            # Every line of the archive            
            for line in fd.readlines():

                # Game attributes
                game_name = line.split(' | ')[0]
                game_price = line.split(' | ')[1]

                # File name
                out_file_name = game_name.replace(" ", "_")
                out_file_name = out_file_name.replace("/", "_")

                # Open the file
                file = open(os.path.join(DATA_PATH, out_file_name), 'a+')

                # Skip repeated dates
                if(file_date in file.read()):
                    continue

                writer = csv.writer(file)

                try:
                    games_dict[game_name][file_date] = game_price
                    writer.writerow([file_date, games_dict[game_name][file_date].rstrip()])
                        
                except KeyError:
                    games_dict[game_name] = {}
