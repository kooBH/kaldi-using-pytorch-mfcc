import numpy as np
import torch
import glob, os
from kaldiio import WriteHelper

data_list = [x for x in glob.glob(os.path.join("../data2/","*.pt")) if not os.path.isdir(x)]


print(data_list)

with WriteHelper('ark,scp:output.ark,output.scp',compression_method=2) as writer :
    for data_path in data_list:
        data = torch.load(data_path)
        data = data.numpy()
        data_name = 'first_data'
        writer(data_name,data)
