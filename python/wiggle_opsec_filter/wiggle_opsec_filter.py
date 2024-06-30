"""
File: wiggle_opsec_filter.py
Author: Patrick Robbins
Date: 30/06/2024
Description: takes a csv file from the wiggle scanner;
    filters out wifi networks based on type, location, and ssid criteria.
"""

#import modules
import csv

filtered_ssid = ['Redbranch', 'TripleFun','ECT5_EXFC']
#lat,lon,lat2,lon2. gps coordinates of the north west and south east points.
filtered_regions = [[33.4391211, -82.1980897, 33.400011, -82.108241]]


#function to check if the location is in the filtered region.
def loc_in_filtered_region(lat, lon):
    if lat == '' or lon == '':#if no gps coordinates are given, return false.
        return False
    
    lat = float(lat)#convert to float
    lon = float(lon)
    for region in filtered_regions:
        if (region[2] <= lat <= region[0]) and (region[1] <= lon <= region[3]):
            return True

    return False
    
#main function, loads input file, applies the filter, and writes to the output file.
def main():
    with open('input.csv', 'r') as infile:
        outfile = open('output.csv', 'w')

        csv_reader = csv.reader(infile)
        next(csv_reader)#skip the first line, which contains device info.
        headers = next(csv_reader)#store the second line as the column names.

        csv_dict_reader = csv.DictReader(infile, fieldnames=headers)
        csv_dict_writer = csv.DictWriter(outfile, fieldnames=headers)
        csv_dict_writer.writeheader()

        for row in csv_dict_reader:
            #only output wifi networks:
            if row['Type'] != 'WIFI':
                continue
            elif row['SSID'] in filtered_ssid:
                continue
            #following line is split in 2 for readability/keeping chars to 80.
            elif loc_in_filtered_region(row['CurrentLatitude'], \
                                        row['CurrentLongitude']):
                continue
            else:
                csv_dict_writer.writerow(row)
        
        #close the output file.
        outfile.close()


# Run the main function, when the script is executed directly.
if __name__ == "__main__":
    main()

# End of File.
