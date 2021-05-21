#! /bin/bash

kaldi_root=/home/kbh/kaldi/egs/chime4_mod/s5_6ch_enhan_clean/

cp kbh_mfcc.sh ${kaldi_root}/
cp run_decode_mfcc.sh ${kaldi_root}/
cp steps/make_mfcc_mfcc.sh ${kaldi_root}/steps/
cp local/run_gmm_mfcc.sh ${kaldi_root}/local/