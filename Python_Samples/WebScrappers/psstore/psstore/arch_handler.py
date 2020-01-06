# -*- coding: utf-8 -*-
import sys
import os

from settings import *

class ArchHandler:

    # Private attributes
    _file = None
    _file_path = ARCH_PATH

    def __init__(self):
        # self._file = open(os.path.join(self._file_path, str(strftime("%Y%m%d", gmtime())) + "___psstore_games"), "w+")
        pass

    def parse(self):
        # Parse every archived file

        games_dict = {}

        for file in os.listdir(ARCH_PATH):
            
            # Get file attributes
            file_date = file.split('_')[0]
            file_name = os.path.join(ARCH_PATH, file)

            fd = open(file_name, "r")

            # Every line of the archive            
            for line in fd.readlines():

                game_name = line.split(' | ')[0]
                game_price = line.split(' | ')[1]

                try:
                    games_dict[game_name][file_date] = game_price
                    # print("==== Added %s to GAMES ====" %(game_name))
                except KeyError:
                    # print("==== Key %s not existant! ====" %(game_name))
                    games_dict[game_name] = {}
                

