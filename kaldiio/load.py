from kaldiio import ReadHelper
with ReadHelper('scp:../samples/raw_mfcc_dt05_real_DCUNET_t12_5.1.scp') as reader :
    for key,numpy_array in reader : 
        print(key)
        print(numpy_array)