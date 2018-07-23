'''
Created on 15/07/2018

@author: ggsg
'''
from TimeUtils import TimeUtils
import logging
import os

def initial_setup():
    
    time_utils = TimeUtils()
    
    logging.basicConfig(filename=("log_" + str(time_utils.get_time())), level=logging.INFO)

if __name__ == "__main__":
    
    print("This is a simple client\n")
    
    # Fetch the data
    c_name = input("Name: ")
    c_id = str(os.getpid())
    
    # Present the data
    print("\nClient Name: " + c_name)
    print("Client ID: " + c_id)
    
    initial_setup()
    
    logging.info("Test")
