# -*- coding: utf-8 -*-

# External libs
import sys
import os
import csv
import unidecode
import logging

import matplotlib.pyplot as plt

# Our own libs
from settings import *

class ArchHandler:

    # Private attributes
    _file = None
    _file_path = ARCH_PATH

    def parse(self):
        # Function to parse every archived file

        games_dict = {}

        # Create data dir if not present
        if not os.path.exists(DATA_PATH):
            os.makedirs(DATA_PATH)
            logging.info("%s was created." %(DATA_PATH))

        # Process the archive
        for file in os.listdir(ARCH_PATH):
                
            logging.info("File '%s' being processed..." %(file))

            # Get file attributes
            file_date = file.split('_')[0]
            file_name = os.path.join(ARCH_PATH, file)

            # Open the archive file
            fd = open(file_name, "r")
            arch_lines = fd.readlines()
            arch_len = len(arch_lines)

            # Every line of the archive            
            for index, line in enumerate(arch_lines):

                logging.info("Line %d/%d." %((index + 1), arch_len))

                # Game attributes
                game_name = line.split(' | ')[0]
                game_price = line.split(' | ')[1]

                # File name trimming (also remove accents)
                out_file_name = game_name.replace(" ", "_")
                out_file_name = out_file_name.replace("/", "_")
                out_file_name = unidecode.unidecode(out_file_name.decode('UTF-8'))

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

    def plot(self):
        # Function to plot the harvested data

        # Exit if the data folder is not present
        if not os.path.exists(DATA_PATH):
            logging.error("%s does not exist." %(DATA_PATH))
            return

        # Get the files
        arch_files = os.listdir(DATA_PATH)
        arch_len = len(arch_files)

        # Process the archive
        for index, file_name in enumerate(arch_files):
        
            # Open the file
            file_fd = open(os.path.join(DATA_PATH, file_name), 'r')
            
            # We'll need this
            x_values = []
            y_values = []

            # Every line of the data file            
            for data_line in file_fd.readlines():
                x_values.append(data_line.split(",")[0])
                y_values.append(data_line.split(",")[1].lstrip('\"').replace("€",""))

            # File name trimming
            out_file_name = file_name.replace(" ", "_")
            out_file_name = out_file_name.replace("/", "_")
            out_file_name = unidecode.unidecode(out_file_name.decode('UTF-8'))
            fig_name = os.path.join("plots", str(out_file_name + ".png"))

            # Save the plots and clear the lib
            plt.plot(x_values, y_values)
            plt.ylabel(out_file_name)
            plt.xticks(rotation='vertical')
            plt.savefig(fig_name)
            plt.clf()

            logging.info("File %d/%d -> Plot generated in '%s'" %((index + 1), arch_len, fig_name))

