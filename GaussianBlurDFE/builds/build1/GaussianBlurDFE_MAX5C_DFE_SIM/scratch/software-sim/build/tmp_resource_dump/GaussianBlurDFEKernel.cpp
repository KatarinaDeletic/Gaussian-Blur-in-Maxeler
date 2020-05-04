#include "stdsimheader.h"
#include "GaussianBlurDFEKernel.h"

namespace maxcompilersim {

GaussianBlurDFEKernel::GaussianBlurDFEKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 26, 2, 1, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0xffffffffl))))
, c_hw_fix_32_0_sgn_bits_1((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000001l))))
, c_hw_fix_32_0_sgn_bits_2((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x000000ffl))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
{
  { // Node ID: 271 (NodeInputMappedReg)
    registerMappedRegister("io_y_force_disabled", Data(1));
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("io_x_force_disabled", Data(1));
  }
  { // Node ID: 2 (NodeInput)
     m_x =  registerInput("x",0,5);
  }
  { // Node ID: 378 (NodeConstantRawBits)
    id378out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    registerMappedRegister("w", Data(32));
  }
  { // Node ID: 288 (NodeConstantRawBits)
    id288out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 377 (NodeConstantRawBits)
    id377out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 376 (NodeConstantRawBits)
    id376out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 290 (NodeConstantRawBits)
    id290out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 375 (NodeConstantRawBits)
    id375out_value = (c_hw_fix_32_0_sgn_bits_1);
  }
  { // Node ID: 374 (NodeConstantRawBits)
    id374out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 373 (NodeConstantRawBits)
    id373out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 372 (NodeConstantRawBits)
    id372out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 371 (NodeConstantRawBits)
    id371out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 370 (NodeConstantRawBits)
    id370out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 369 (NodeConstantRawBits)
    id369out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 368 (NodeConstantRawBits)
    id368out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 367 (NodeConstantRawBits)
    id367out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 366 (NodeConstantRawBits)
    id366out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 365 (NodeConstantRawBits)
    id365out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 364 (NodeConstantRawBits)
    id364out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 363 (NodeConstantRawBits)
    id363out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 362 (NodeConstantRawBits)
    id362out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 361 (NodeConstantRawBits)
    id361out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 360 (NodeConstantRawBits)
    id360out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 359 (NodeConstantRawBits)
    id359out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 358 (NodeConstantRawBits)
    id358out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 357 (NodeConstantRawBits)
    id357out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 356 (NodeConstantRawBits)
    id356out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 355 (NodeConstantRawBits)
    id355out_value = (c_hw_fix_32_0_sgn_bits_2);
  }
  { // Node ID: 274 (NodeOutput)
    m_y = registerOutput("y",0 );
  }
  { // Node ID: 279 (NodeConstantRawBits)
    id279out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 354 (NodeConstantRawBits)
    id354out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 276 (NodeConstantRawBits)
    id276out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 280 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 353 (NodeConstantRawBits)
    id353out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 282 (NodeConstantRawBits)
    id282out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 285 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
  { // Node ID: 4 (NodeInputMappedReg)
    registerMappedRegister("size", Data(32));
  }
}

void GaussianBlurDFEKernel::ramInitialise() {
}

void GaussianBlurDFEKernel::resetComputation() {
  resetComputationAfterFlush();
}

void GaussianBlurDFEKernel::resetComputationAfterFlush() {
  { // Node ID: 271 (NodeInputMappedReg)
    id271out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_x_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_x_force_disabled");
  }
  { // Node ID: 2 (NodeInput)

    (id2st_read_next_cycle) = (c_hw_fix_1_0_uns_bits);
    (id2st_last_read_value) = (HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 379 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id379out_output[i] = (HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_w = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("w");
  }
  { // Node ID: 27 (NodeDynamicStreamOffset)

    (id27st_endOfBuffer) = (0l);
  }
  { // Node ID: 34 (NodeDynamicStreamOffset)

    (id34st_endOfBuffer) = (0l);
  }
  { // Node ID: 40 (NodeDynamicStreamOffset)

    (id40st_endOfBuffer) = (0l);
  }
  { // Node ID: 391 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id391out_output[i] = (HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 392 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id392out_output[i] = (HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 47 (NodeDynamicStreamOffset)

    (id47st_endOfBuffer) = (0l);
  }
  { // Node ID: 393 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id393out_output[i] = (HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 394 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id394out_output[i] = (HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 395 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id395out_output[i] = (HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 58 (NodeDynamicStreamOffset)

    (id58st_endOfBuffer) = (0l);
  }
  { // Node ID: 65 (NodeDynamicStreamOffset)

    (id65st_endOfBuffer) = (0l);
  }
  { // Node ID: 71 (NodeDynamicStreamOffset)

    (id71st_endOfBuffer) = (0l);
  }
  { // Node ID: 77 (NodeDynamicStreamOffset)

    (id77st_endOfBuffer) = (0l);
  }
  { // Node ID: 388 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id388out_output[i] = (HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 390 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id390out_output[i] = (HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 277 (NodeCounter)

    (id277st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 283 (NodeCounter)

    (id283st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 285 (NodeInputMappedReg)
    id285out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_size = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("size");
  }
}

void GaussianBlurDFEKernel::updateState() {
  { // Node ID: 271 (NodeInputMappedReg)
    id271out_io_y_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_y_force_disabled");
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_io_x_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_x_force_disabled");
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_w = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("w");
  }
  { // Node ID: 285 (NodeInputMappedReg)
    id285out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_size = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("size");
  }
}

void GaussianBlurDFEKernel::preExecute() {
  { // Node ID: 2 (NodeInput)
    if(((needsToReadInput(m_x))&(((getFlushLevel())<((4l)+(5)))|(!(isFlushingActive()))))) {
      (id2st_last_read_value) = (readInput<HWOffsetFix<32,0,TWOSCOMPLEMENT> >(m_x));
    }
    id2out_data = (id2st_last_read_value);
  }
}

void GaussianBlurDFEKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "GaussianBlurDFEKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int GaussianBlurDFEKernel::getFlushLevelStart() {
  return ((1l)+(3l));
}

}
