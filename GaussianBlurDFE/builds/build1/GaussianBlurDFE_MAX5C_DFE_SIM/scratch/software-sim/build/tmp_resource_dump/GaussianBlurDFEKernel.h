#ifndef GAUSSIANBLURDFEKERNEL_H_
#define GAUSSIANBLURDFEKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class GaussianBlurDFEKernel : public KernelManagerBlockSync {
public:
  GaussianBlurDFEKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void ramInitialise();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_x;
  t_port_number m_y;
  HWOffsetFix<1,0,UNSIGNED> id271out_io_y_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id0out_io_x_force_disabled;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_data;

  HWOffsetFix<1,0,UNSIGNED> id2st_read_next_cycle;
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2st_last_read_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id379out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id378out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id3out_w;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id292out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id27out_output[4];

  long id27st_endOfBuffer;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id27sta_buffer[8];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id288out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id34out_output[4];

  long id34st_endOfBuffer;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id34sta_buffer[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id116out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id377out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id38out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id40out_output[4];

  long id40st_endOfBuffer;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id40sta_buffer[4];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id135out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id391out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id392out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id298out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id47out_output[4];

  long id47st_endOfBuffer;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id47sta_buffer[4];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id154out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id393out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id394out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id395out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id173out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id58out_output[4];

  long id58st_endOfBuffer;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id58sta_buffer[4];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id192out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id376out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id309out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id65out_output[4];

  long id65st_endOfBuffer;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id65sta_buffer[4];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id211out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id290out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id71out_output[4];

  long id71st_endOfBuffer;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id71sta_buffer[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id230out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id375out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id75out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id77out_output[4];

  long id77st_endOfBuffer;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id77sta_buffer[8];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id249out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id316out_o[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id388out_output[3];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id374out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id88out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id373out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id107out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id117out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id372out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id126out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id136out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id371out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id145out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id155out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id370out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id164out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id174out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id369out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id183out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id193out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id368out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id202out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id212out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id367out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id221out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id231out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id366out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id240out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id250out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id338out_o[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id365out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id262out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id263out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id364out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id90out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id363out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id109out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id118out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id362out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id128out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id137out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id361out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id147out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id156out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id360out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id166out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id175out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id359out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id185out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id194out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id358out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id204out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id213out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id357out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id223out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id232out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id356out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id242out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id251out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id351out_o[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id355out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id268out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id390out_output[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id269out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id279out_value;

  HWOffsetFix<1,0,UNSIGNED> id354out_value;

  HWOffsetFix<49,0,UNSIGNED> id276out_value;

  HWOffsetFix<48,0,UNSIGNED> id277out_count;
  HWOffsetFix<1,0,UNSIGNED> id277out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id277st_count;

  HWOffsetFix<1,0,UNSIGNED> id353out_value;

  HWOffsetFix<49,0,UNSIGNED> id282out_value;

  HWOffsetFix<48,0,UNSIGNED> id283out_count;
  HWOffsetFix<1,0,UNSIGNED> id283out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id283st_count;

  HWOffsetFix<48,0,UNSIGNED> id285out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id352out_result[2];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id4out_size;

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_1;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* GAUSSIANBLURDFEKERNEL_H_ */
