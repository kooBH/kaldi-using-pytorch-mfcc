#!/bin/bash

if [ -z "$1" ]
then
  echo Need 'TARGET' as argument
  exit 1
fi
echo $1

TARGET=$1

dirs_all=("et05_simu" "dt05_simu" "tr05_simu" "et05_real" "dt05_real" "tr05_real")
dirs_test=("dt05_simu" "dt05_real" "et05_simu" "et05_real")

for idx in 0 1 2 3 4 5; do
	rm data/${dirs_test[$idx]}_${TARGET}/*
  rm -r data/local/data/${dirs_all[$idx]}_${TARGET}
done

# cp valid CHiME4 data from other data
for idx in 0 1 2 3; do
  mkdir data/${dirs_test[$idx]}_${TARGET}
  cp data/${dirs_test[$idx]}_DCUNET_t12_5/text data/${dirs_test[$idx]}_${TARGET}/
  cp data/${dirs_test[$idx]}_DCUNET_t12_5/wav.scp data/${dirs_test[$idx]}_${TARGET}/
  cp data/${dirs_test[$idx]}_DCUNET_t12_5/utt2spk data/${dirs_test[$idx]}_${TARGET}/
  cp data/${dirs_test[$idx]}_DCUNET_t12_5/spk2utt data/${dirs_test[$idx]}_${TARGET}/
done
 ./run_decode_mfcc.sh ${TARGET} /home/data/kbh/CHiME4_CGMM_RLS/trial_04/ > /home/nas/user/kbh/MCFE/${TARGET}.txt

for idx in 0 1 2 3 4 5; do
	rm data/${dirs_test[$idx]}_${TARGET}/*
  rm -r data/local/data/${dirs_all[$idx]}_${TARGET}
done



rm -r data/et05_multi_${TARGET}*
rm -r data/dt05_multi_${TARGET}*
#
#for idx in 0 1 2 3 4 5; do
	rm -r exp/make_mfcc/${dirs_all[$idx]}_${TARGET}*
	rm -r exp/chain/tdnn1a_sp/decode_tgpr_5k_${dirs_all[$idx]}_${TARGET}*
	rm -r exp/chain/tdnn1a_sp_smbr_lmrescore/decode_tgpr_5k_${dirs_all[$idx]}_${TARGET}*
	rm exp/chain/tdnn1a_sp_smbr_lmrescore/best_wer_${dirs_all[$idx]}_${TARGET}*
	rm -r exp/nnet3/ivectors_${dirs_all[$idx]}_${TARGET}*
#
#done
rm -r exp/tri3b_tr05_multi_noisy/best_wer_${TARGET}*
rm -r mfcc/${TARGET}*

