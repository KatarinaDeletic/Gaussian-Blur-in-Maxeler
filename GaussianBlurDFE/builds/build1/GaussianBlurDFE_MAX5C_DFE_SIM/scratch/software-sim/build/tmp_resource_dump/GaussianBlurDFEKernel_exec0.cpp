#include "stdsimheader.h"

namespace maxcompilersim {

void GaussianBlurDFEKernel::execute0() {
  { // Node ID: 271 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id272out_result;

  { // Node ID: 272 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id272in_a = id271out_io_y_force_disabled;

    id272out_result = (not_fixed(id272in_a));
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id1out_result;

  { // Node ID: 1 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id1in_a = id0out_io_x_force_disabled;

    id1out_result = (not_fixed(id1in_a));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 2 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id2in_enable = id1out_result;

    (id2st_read_next_cycle) = ((id2in_enable.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    queueReadRequest(m_x, id2st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 379 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id379in_input = id2out_data;

    id379out_output[(getCycle()+1)%2] = id379in_input;
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id25out_output;

  { // Node ID: 25 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id25in_input = id379out_output[getCycle()%2];

    id25out_output = id25in_input;
  }
  { // Node ID: 378 (NodeConstantRawBits)
  }
  { // Node ID: 3 (NodeInputMappedReg)
  }
  { // Node ID: 292 (NodeSub)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id292in_a = id378out_value;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id292in_b = id3out_w;

    id292out_result[(getCycle()+1)%2] = (sub_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id292in_a,id292in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id26out_output;

  { // Node ID: 26 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id26in_input = id292out_result[getCycle()%2];

    id26out_output = id26in_input;
  }
  { // Node ID: 27 (NodeDynamicStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id27in_input = id25out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id27in_offset = id26out_output;

    (id27sta_buffer[(id27st_endOfBuffer)]) = id27in_input;
    id27out_output[(getCycle()+3)%4] = (id27sta_buffer[((((id27st_endOfBuffer)+(id27in_offset.getValueAsLong()))-(0l))&(7l))]);
    (id27st_endOfBuffer) = (((id27st_endOfBuffer)+(1l))&(7l));
  }
  HWRawBits<32> id293out_dataout;

  { // Node ID: 293 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id293in_datain = id27out_output[getCycle()%4];

    id293out_dataout = (shift_right_fixed(id293in_datain,(16l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id83out_output;

  { // Node ID: 83 (NodeReinterpret)
    const HWRawBits<32> &id83in_input = id293out_dataout;

    id83out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id83in_input));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id32out_output;

  { // Node ID: 32 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id32in_input = id379out_output[getCycle()%2];

    id32out_output = id32in_input;
  }
  { // Node ID: 288 (NodeConstantRawBits)
  }
  { // Node ID: 34 (NodeDynamicStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id34in_input = id32out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id34in_offset = id288out_value;

    (id34sta_buffer[(id34st_endOfBuffer)]) = id34in_input;
    id34out_output[(getCycle()+3)%4] = (id34sta_buffer[((((id34st_endOfBuffer)+(id34in_offset.getValueAsLong()))-(0l))&(1l))]);
    (id34st_endOfBuffer) = (((id34st_endOfBuffer)+(1l))&(1l));
  }
  HWRawBits<32> id294out_dataout;

  { // Node ID: 294 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id294in_datain = id34out_output[getCycle()%4];

    id294out_dataout = (shift_right_fixed(id294in_datain,(16l)));
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id295out_output;

  { // Node ID: 295 (NodeReinterpret)
    const HWRawBits<32> &id295in_input = id294out_dataout;

    id295out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>(id295in_input));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id296out_o;

  { // Node ID: 296 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id296in_i = id295out_output;

    id296out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id296in_i));
  }
  { // Node ID: 116 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id116in_a = id83out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id116in_b = id296out_o;

    id116out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id116in_a,id116in_b));
  }
  { // Node ID: 377 (NodeConstantRawBits)
  }
  { // Node ID: 38 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id38in_a = id3out_w;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id38in_b = id377out_value;

    id38out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id38in_a,id38in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id39out_output;

  { // Node ID: 39 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id39in_input = id38out_result[getCycle()%2];

    id39out_output = id39in_input;
  }
  { // Node ID: 40 (NodeDynamicStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id40in_input = id2out_data;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id40in_offset = id39out_output;

    (id40sta_buffer[(id40st_endOfBuffer)]) = id40in_input;
    id40out_output[(getCycle()+3)%4] = (id40sta_buffer[((((id40st_endOfBuffer)+(id40in_offset.getValueAsLong()))-(2l))&(3l))]);
    (id40st_endOfBuffer) = (((id40st_endOfBuffer)+(1l))&(3l));
  }
  HWRawBits<32> id297out_dataout;

  { // Node ID: 297 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id297in_datain = id40out_output[getCycle()%4];

    id297out_dataout = (shift_right_fixed(id297in_datain,(16l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id121out_output;

  { // Node ID: 121 (NodeReinterpret)
    const HWRawBits<32> &id121in_input = id297out_dataout;

    id121out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id121in_input));
  }
  { // Node ID: 135 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id135in_a = id116out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id135in_b = id121out_output;

    id135out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id135in_a,id135in_b));
  }
  { // Node ID: 391 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id391in_input = id379out_output[getCycle()%2];

    id391out_output[(getCycle()+1)%2] = id391in_input;
  }
  { // Node ID: 392 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id392in_input = id391out_output[getCycle()%2];

    id392out_output[(getCycle()+1)%2] = id392in_input;
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id45out_output;

  { // Node ID: 45 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id45in_input = id392out_output[getCycle()%2];

    id45out_output = id45in_input;
  }
  { // Node ID: 298 (NodeNeg)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id298in_a = id3out_w;

    id298out_result[(getCycle()+1)%2] = (neg_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id298in_a));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id46out_output;

  { // Node ID: 46 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id46in_input = id298out_result[getCycle()%2];

    id46out_output = id46in_input;
  }
  { // Node ID: 47 (NodeDynamicStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id47in_input = id45out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id47in_offset = id46out_output;

    (id47sta_buffer[(id47st_endOfBuffer)]) = id47in_input;
    id47out_output[(getCycle()+3)%4] = (id47sta_buffer[((((id47st_endOfBuffer)+(id47in_offset.getValueAsLong()))-(0l))&(3l))]);
    (id47st_endOfBuffer) = (((id47st_endOfBuffer)+(1l))&(3l));
  }
  HWRawBits<32> id299out_dataout;

  { // Node ID: 299 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id299in_datain = id47out_output[getCycle()%4];

    id299out_dataout = (shift_right_fixed(id299in_datain,(16l)));
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id300out_output;

  { // Node ID: 300 (NodeReinterpret)
    const HWRawBits<32> &id300in_input = id299out_dataout;

    id300out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>(id300in_input));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id301out_o;

  { // Node ID: 301 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id301in_i = id300out_output;

    id301out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id301in_i));
  }
  { // Node ID: 154 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id154in_a = id135out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id154in_b = id301out_o;

    id154out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id154in_a,id154in_b));
  }
  { // Node ID: 393 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id393in_input = id392out_output[getCycle()%2];

    id393out_output[(getCycle()+1)%2] = id393in_input;
  }
  { // Node ID: 394 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id394in_input = id393out_output[getCycle()%2];

    id394out_output[(getCycle()+2)%3] = id394in_input;
  }
  { // Node ID: 395 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id395in_input = id394out_output[getCycle()%3];

    id395out_output[(getCycle()+1)%2] = id395in_input;
  }
  HWRawBits<32> id302out_dataout;

  { // Node ID: 302 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id302in_datain = id395out_output[getCycle()%2];

    id302out_dataout = (shift_right_fixed(id302in_datain,(16l)));
  }
  HWOffsetFix<32,2,TWOSCOMPLEMENT> id303out_output;

  { // Node ID: 303 (NodeReinterpret)
    const HWRawBits<32> &id303in_input = id302out_dataout;

    id303out_output = (cast_bits2fixed<32,2,TWOSCOMPLEMENT>(id303in_input));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id304out_o;

  { // Node ID: 304 (NodeCast)
    const HWOffsetFix<32,2,TWOSCOMPLEMENT> &id304in_i = id303out_output;

    id304out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id304in_i));
  }
  { // Node ID: 173 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id173in_a = id154out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id173in_b = id304out_o;

    id173out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id173in_a,id173in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id57out_output;

  { // Node ID: 57 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id57in_input = id3out_w;

    id57out_output = id57in_input;
  }
  { // Node ID: 58 (NodeDynamicStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id58in_input = id391out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id58in_offset = id57out_output;

    (id58sta_buffer[(id58st_endOfBuffer)]) = id58in_input;
    id58out_output[(getCycle()+3)%4] = (id58sta_buffer[((((id58st_endOfBuffer)+(id58in_offset.getValueAsLong()))-(3l))&(3l))]);
    (id58st_endOfBuffer) = (((id58st_endOfBuffer)+(1l))&(3l));
  }
  HWRawBits<32> id305out_dataout;

  { // Node ID: 305 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id305in_datain = id58out_output[getCycle()%4];

    id305out_dataout = (shift_right_fixed(id305in_datain,(16l)));
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id306out_output;

  { // Node ID: 306 (NodeReinterpret)
    const HWRawBits<32> &id306in_input = id305out_dataout;

    id306out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>(id306in_input));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id307out_o;

  { // Node ID: 307 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id307in_i = id306out_output;

    id307out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id307in_i));
  }
  { // Node ID: 192 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id192in_a = id173out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id192in_b = id307out_o;

    id192out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id192in_a,id192in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id63out_output;

  { // Node ID: 63 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id63in_input = id394out_output[getCycle()%3];

    id63out_output = id63in_input;
  }
  { // Node ID: 376 (NodeConstantRawBits)
  }
  { // Node ID: 309 (NodeSub)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id309in_a = id376out_value;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id309in_b = id3out_w;

    id309out_result[(getCycle()+1)%2] = (sub_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id309in_a,id309in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id64out_output;

  { // Node ID: 64 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id64in_input = id309out_result[getCycle()%2];

    id64out_output = id64in_input;
  }
  { // Node ID: 65 (NodeDynamicStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id65in_input = id63out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id65in_offset = id64out_output;

    (id65sta_buffer[(id65st_endOfBuffer)]) = id65in_input;
    id65out_output[(getCycle()+3)%4] = (id65sta_buffer[((((id65st_endOfBuffer)+(id65in_offset.getValueAsLong()))-(0l))&(3l))]);
    (id65st_endOfBuffer) = (((id65st_endOfBuffer)+(1l))&(3l));
  }
  HWRawBits<32> id310out_dataout;

  { // Node ID: 310 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id310in_datain = id65out_output[getCycle()%4];

    id310out_dataout = (shift_right_fixed(id310in_datain,(16l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id197out_output;

  { // Node ID: 197 (NodeReinterpret)
    const HWRawBits<32> &id197in_input = id310out_dataout;

    id197out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id197in_input));
  }
  { // Node ID: 211 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id211in_a = id192out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id211in_b = id197out_output;

    id211out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id211in_a,id211in_b));
  }
  { // Node ID: 290 (NodeConstantRawBits)
  }
  { // Node ID: 71 (NodeDynamicStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id71in_input = id394out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id71in_offset = id290out_value;

    (id71sta_buffer[(id71st_endOfBuffer)]) = id71in_input;
    id71out_output[(getCycle()+3)%4] = (id71sta_buffer[((((id71st_endOfBuffer)+(id71in_offset.getValueAsLong()))-(1l))&(1l))]);
    (id71st_endOfBuffer) = (((id71st_endOfBuffer)+(1l))&(1l));
  }
  HWRawBits<32> id311out_dataout;

  { // Node ID: 311 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id311in_datain = id71out_output[getCycle()%4];

    id311out_dataout = (shift_right_fixed(id311in_datain,(16l)));
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id312out_output;

  { // Node ID: 312 (NodeReinterpret)
    const HWRawBits<32> &id312in_input = id311out_dataout;

    id312out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>(id312in_input));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id313out_o;

  { // Node ID: 313 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id313in_i = id312out_output;

    id313out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id313in_i));
  }
  { // Node ID: 230 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id230in_a = id211out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id230in_b = id313out_o;

    id230out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id230in_a,id230in_b));
  }
  { // Node ID: 375 (NodeConstantRawBits)
  }
  { // Node ID: 75 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id75in_a = id3out_w;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id75in_b = id375out_value;

    id75out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id75in_a,id75in_b));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id76out_output;

  { // Node ID: 76 (NodeStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id76in_input = id75out_result[getCycle()%2];

    id76out_output = id76in_input;
  }
  { // Node ID: 77 (NodeDynamicStreamOffset)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id77in_input = id393out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id77in_offset = id76out_output;

    (id77sta_buffer[(id77st_endOfBuffer)]) = id77in_input;
    id77out_output[(getCycle()+3)%4] = (id77sta_buffer[((((id77st_endOfBuffer)+(id77in_offset.getValueAsLong()))-(4l))&(7l))]);
    (id77st_endOfBuffer) = (((id77st_endOfBuffer)+(1l))&(7l));
  }
  HWRawBits<32> id314out_dataout;

  { // Node ID: 314 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id314in_datain = id77out_output[getCycle()%4];

    id314out_dataout = (shift_right_fixed(id314in_datain,(16l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id235out_output;

  { // Node ID: 235 (NodeReinterpret)
    const HWRawBits<32> &id235in_input = id314out_dataout;

    id235out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id235in_input));
  }
  { // Node ID: 249 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id249in_a = id230out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id249in_b = id235out_output;

    id249out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id249in_a,id249in_b));
  }
  HWOffsetFix<32,-4,TWOSCOMPLEMENT> id315out_output;

  { // Node ID: 315 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id315in_input = id249out_result[getCycle()%2];

    id315out_output = (cast_bits2fixed<32,-4,TWOSCOMPLEMENT>((cast_fixed2bits(id315in_input))));
  }
  { // Node ID: 316 (NodeCast)
    const HWOffsetFix<32,-4,TWOSCOMPLEMENT> &id316in_i = id315out_output;

    id316out_o[(getCycle()+1)%2] = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id316in_i));
  }
  HWRawBits<32> id317out_dataout;

  { // Node ID: 317 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id317in_datain = id316out_o[getCycle()%2];

    id317out_dataout = (shift_left_fixed(id317in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id260out_output;

  { // Node ID: 260 (NodeReinterpret)
    const HWRawBits<32> &id260in_input = id317out_dataout;

    id260out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id260in_input));
  }
  { // Node ID: 388 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id388in_input = id260out_output;

    id388out_output[(getCycle()+2)%3] = id388in_input;
  }
  HWRawBits<32> id318out_dataout;

  { // Node ID: 318 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id318in_datain = id27out_output[getCycle()%4];

    id318out_dataout = (shift_right_fixed(id318in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id86out_output;

  { // Node ID: 86 (NodeReinterpret)
    const HWRawBits<32> &id86in_input = id318out_dataout;

    id86out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id86in_input));
  }
  { // Node ID: 374 (NodeConstantRawBits)
  }
  { // Node ID: 88 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id88in_a = id86out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id88in_b = id374out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id88x_1;

    (id88x_1) = (and_fixed(id88in_a,id88in_b));
    id88out_result[(getCycle()+1)%2] = (id88x_1);
  }
  HWRawBits<32> id319out_dataout;

  { // Node ID: 319 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id319in_datain = id34out_output[getCycle()%4];

    id319out_dataout = (shift_right_fixed(id319in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id105out_output;

  { // Node ID: 105 (NodeReinterpret)
    const HWRawBits<32> &id105in_input = id319out_dataout;

    id105out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id105in_input));
  }
  { // Node ID: 373 (NodeConstantRawBits)
  }
  { // Node ID: 107 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id107in_a = id105out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id107in_b = id373out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id107x_1;

    (id107x_1) = (and_fixed(id107in_a,id107in_b));
    id107out_result[(getCycle()+1)%2] = (id107x_1);
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id320out_output;

  { // Node ID: 320 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id320in_input = id107out_result[getCycle()%2];

    id320out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>((cast_fixed2bits(id320in_input))));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id321out_o;

  { // Node ID: 321 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id321in_i = id320out_output;

    id321out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id321in_i));
  }
  { // Node ID: 117 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id117in_a = id88out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id117in_b = id321out_o;

    id117out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id117in_a,id117in_b));
  }
  HWRawBits<32> id322out_dataout;

  { // Node ID: 322 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id322in_datain = id40out_output[getCycle()%4];

    id322out_dataout = (shift_right_fixed(id322in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id124out_output;

  { // Node ID: 124 (NodeReinterpret)
    const HWRawBits<32> &id124in_input = id322out_dataout;

    id124out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id124in_input));
  }
  { // Node ID: 372 (NodeConstantRawBits)
  }
  { // Node ID: 126 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id126in_a = id124out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id126in_b = id372out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id126x_1;

    (id126x_1) = (and_fixed(id126in_a,id126in_b));
    id126out_result[(getCycle()+1)%2] = (id126x_1);
  }
  { // Node ID: 136 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id136in_a = id117out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id136in_b = id126out_result[getCycle()%2];

    id136out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id136in_a,id136in_b));
  }
  HWRawBits<32> id323out_dataout;

  { // Node ID: 323 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id323in_datain = id47out_output[getCycle()%4];

    id323out_dataout = (shift_right_fixed(id323in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id143out_output;

  { // Node ID: 143 (NodeReinterpret)
    const HWRawBits<32> &id143in_input = id323out_dataout;

    id143out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id143in_input));
  }
  { // Node ID: 371 (NodeConstantRawBits)
  }
  { // Node ID: 145 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id145in_a = id143out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id145in_b = id371out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id145x_1;

    (id145x_1) = (and_fixed(id145in_a,id145in_b));
    id145out_result[(getCycle()+1)%2] = (id145x_1);
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id324out_output;

  { // Node ID: 324 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id324in_input = id145out_result[getCycle()%2];

    id324out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>((cast_fixed2bits(id324in_input))));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id325out_o;

  { // Node ID: 325 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id325in_i = id324out_output;

    id325out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id325in_i));
  }
  { // Node ID: 155 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id155in_a = id136out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id155in_b = id325out_o;

    id155out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id155in_a,id155in_b));
  }
  HWRawBits<32> id326out_dataout;

  { // Node ID: 326 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id326in_datain = id395out_output[getCycle()%2];

    id326out_dataout = (shift_right_fixed(id326in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id162out_output;

  { // Node ID: 162 (NodeReinterpret)
    const HWRawBits<32> &id162in_input = id326out_dataout;

    id162out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id162in_input));
  }
  { // Node ID: 370 (NodeConstantRawBits)
  }
  { // Node ID: 164 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id164in_a = id162out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id164in_b = id370out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id164x_1;

    (id164x_1) = (and_fixed(id164in_a,id164in_b));
    id164out_result[(getCycle()+1)%2] = (id164x_1);
  }
  HWOffsetFix<32,2,TWOSCOMPLEMENT> id327out_output;

  { // Node ID: 327 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id327in_input = id164out_result[getCycle()%2];

    id327out_output = (cast_bits2fixed<32,2,TWOSCOMPLEMENT>((cast_fixed2bits(id327in_input))));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id328out_o;

  { // Node ID: 328 (NodeCast)
    const HWOffsetFix<32,2,TWOSCOMPLEMENT> &id328in_i = id327out_output;

    id328out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id328in_i));
  }
  { // Node ID: 174 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id174in_a = id155out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id174in_b = id328out_o;

    id174out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id174in_a,id174in_b));
  }
  HWRawBits<32> id329out_dataout;

  { // Node ID: 329 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id329in_datain = id58out_output[getCycle()%4];

    id329out_dataout = (shift_right_fixed(id329in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id181out_output;

  { // Node ID: 181 (NodeReinterpret)
    const HWRawBits<32> &id181in_input = id329out_dataout;

    id181out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id181in_input));
  }
  { // Node ID: 369 (NodeConstantRawBits)
  }
  { // Node ID: 183 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id183in_a = id181out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id183in_b = id369out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id183x_1;

    (id183x_1) = (and_fixed(id183in_a,id183in_b));
    id183out_result[(getCycle()+1)%2] = (id183x_1);
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id330out_output;

  { // Node ID: 330 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id330in_input = id183out_result[getCycle()%2];

    id330out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>((cast_fixed2bits(id330in_input))));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id331out_o;

  { // Node ID: 331 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id331in_i = id330out_output;

    id331out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id331in_i));
  }
  { // Node ID: 193 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id193in_a = id174out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id193in_b = id331out_o;

    id193out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id193in_a,id193in_b));
  }
  HWRawBits<32> id332out_dataout;

  { // Node ID: 332 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id332in_datain = id65out_output[getCycle()%4];

    id332out_dataout = (shift_right_fixed(id332in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id200out_output;

  { // Node ID: 200 (NodeReinterpret)
    const HWRawBits<32> &id200in_input = id332out_dataout;

    id200out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id200in_input));
  }
  { // Node ID: 368 (NodeConstantRawBits)
  }
  { // Node ID: 202 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id202in_a = id200out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id202in_b = id368out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id202x_1;

    (id202x_1) = (and_fixed(id202in_a,id202in_b));
    id202out_result[(getCycle()+1)%2] = (id202x_1);
  }
  { // Node ID: 212 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id212in_a = id193out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id212in_b = id202out_result[getCycle()%2];

    id212out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id212in_a,id212in_b));
  }
  HWRawBits<32> id333out_dataout;

  { // Node ID: 333 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id333in_datain = id71out_output[getCycle()%4];

    id333out_dataout = (shift_right_fixed(id333in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id219out_output;

  { // Node ID: 219 (NodeReinterpret)
    const HWRawBits<32> &id219in_input = id333out_dataout;

    id219out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id219in_input));
  }
  { // Node ID: 367 (NodeConstantRawBits)
  }
  { // Node ID: 221 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id221in_a = id219out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id221in_b = id367out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id221x_1;

    (id221x_1) = (and_fixed(id221in_a,id221in_b));
    id221out_result[(getCycle()+1)%2] = (id221x_1);
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id334out_output;

  { // Node ID: 334 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id334in_input = id221out_result[getCycle()%2];

    id334out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>((cast_fixed2bits(id334in_input))));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id335out_o;

  { // Node ID: 335 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id335in_i = id334out_output;

    id335out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id335in_i));
  }
  { // Node ID: 231 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id231in_a = id212out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id231in_b = id335out_o;

    id231out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id231in_a,id231in_b));
  }
  HWRawBits<32> id336out_dataout;

  { // Node ID: 336 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id336in_datain = id77out_output[getCycle()%4];

    id336out_dataout = (shift_right_fixed(id336in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id238out_output;

  { // Node ID: 238 (NodeReinterpret)
    const HWRawBits<32> &id238in_input = id336out_dataout;

    id238out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id238in_input));
  }
  { // Node ID: 366 (NodeConstantRawBits)
  }
  { // Node ID: 240 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id240in_a = id238out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id240in_b = id366out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id240x_1;

    (id240x_1) = (and_fixed(id240in_a,id240in_b));
    id240out_result[(getCycle()+1)%2] = (id240x_1);
  }
  { // Node ID: 250 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id250in_a = id231out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id250in_b = id240out_result[getCycle()%2];

    id250out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id250in_a,id250in_b));
  }
  HWOffsetFix<32,-4,TWOSCOMPLEMENT> id337out_output;

  { // Node ID: 337 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id337in_input = id250out_result[getCycle()%2];

    id337out_output = (cast_bits2fixed<32,-4,TWOSCOMPLEMENT>((cast_fixed2bits(id337in_input))));
  }
  { // Node ID: 338 (NodeCast)
    const HWOffsetFix<32,-4,TWOSCOMPLEMENT> &id338in_i = id337out_output;

    id338out_o[(getCycle()+1)%2] = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id338in_i));
  }
  { // Node ID: 365 (NodeConstantRawBits)
  }
  { // Node ID: 262 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id262in_a = id338out_o[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id262in_b = id365out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id262x_1;

    (id262x_1) = (and_fixed(id262in_a,id262in_b));
    id262out_result[(getCycle()+1)%2] = (id262x_1);
  }
  { // Node ID: 263 (NodeOr)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id263in_a = id388out_output[getCycle()%3];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id263in_b = id262out_result[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id263x_1;

    (id263x_1) = (or_fixed(id263in_a,id263in_b));
    id263out_result[(getCycle()+1)%2] = (id263x_1);
  }
  HWRawBits<32> id339out_dataout;

  { // Node ID: 339 (NodeShift)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id339in_datain = id263out_result[getCycle()%2];

    id339out_dataout = (shift_left_fixed(id339in_datain,(8l)));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id266out_output;

  { // Node ID: 266 (NodeReinterpret)
    const HWRawBits<32> &id266in_input = id339out_dataout;

    id266out_output = (cast_bits2fixed<32,0,TWOSCOMPLEMENT>(id266in_input));
  }
  { // Node ID: 364 (NodeConstantRawBits)
  }
  { // Node ID: 90 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id90in_a = id27out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id90in_b = id364out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id90x_1;

    (id90x_1) = (and_fixed(id90in_a,id90in_b));
    id90out_result[(getCycle()+1)%2] = (id90x_1);
  }
  { // Node ID: 363 (NodeConstantRawBits)
  }
  { // Node ID: 109 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id109in_a = id34out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id109in_b = id363out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id109x_1;

    (id109x_1) = (and_fixed(id109in_a,id109in_b));
    id109out_result[(getCycle()+1)%2] = (id109x_1);
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id340out_output;

  { // Node ID: 340 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id340in_input = id109out_result[getCycle()%2];

    id340out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>((cast_fixed2bits(id340in_input))));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id341out_o;

  { // Node ID: 341 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id341in_i = id340out_output;

    id341out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id341in_i));
  }
  { // Node ID: 118 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id118in_a = id90out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id118in_b = id341out_o;

    id118out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id118in_a,id118in_b));
  }
  { // Node ID: 362 (NodeConstantRawBits)
  }
  { // Node ID: 128 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id128in_a = id40out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id128in_b = id362out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id128x_1;

    (id128x_1) = (and_fixed(id128in_a,id128in_b));
    id128out_result[(getCycle()+1)%2] = (id128x_1);
  }
  { // Node ID: 137 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id137in_a = id118out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id137in_b = id128out_result[getCycle()%2];

    id137out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id137in_a,id137in_b));
  }
  { // Node ID: 361 (NodeConstantRawBits)
  }
  { // Node ID: 147 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id147in_a = id47out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id147in_b = id361out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id147x_1;

    (id147x_1) = (and_fixed(id147in_a,id147in_b));
    id147out_result[(getCycle()+1)%2] = (id147x_1);
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id342out_output;

  { // Node ID: 342 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id342in_input = id147out_result[getCycle()%2];

    id342out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>((cast_fixed2bits(id342in_input))));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id343out_o;

  { // Node ID: 343 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id343in_i = id342out_output;

    id343out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id343in_i));
  }
  { // Node ID: 156 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id156in_a = id137out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id156in_b = id343out_o;

    id156out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id156in_a,id156in_b));
  }
  { // Node ID: 360 (NodeConstantRawBits)
  }
  { // Node ID: 166 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id166in_a = id395out_output[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id166in_b = id360out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id166x_1;

    (id166x_1) = (and_fixed(id166in_a,id166in_b));
    id166out_result[(getCycle()+1)%2] = (id166x_1);
  }
  HWOffsetFix<32,2,TWOSCOMPLEMENT> id344out_output;

  { // Node ID: 344 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id344in_input = id166out_result[getCycle()%2];

    id344out_output = (cast_bits2fixed<32,2,TWOSCOMPLEMENT>((cast_fixed2bits(id344in_input))));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id345out_o;

  { // Node ID: 345 (NodeCast)
    const HWOffsetFix<32,2,TWOSCOMPLEMENT> &id345in_i = id344out_output;

    id345out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id345in_i));
  }
  { // Node ID: 175 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id175in_a = id156out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id175in_b = id345out_o;

    id175out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id175in_a,id175in_b));
  }
  { // Node ID: 359 (NodeConstantRawBits)
  }
  { // Node ID: 185 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id185in_a = id58out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id185in_b = id359out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id185x_1;

    (id185x_1) = (and_fixed(id185in_a,id185in_b));
    id185out_result[(getCycle()+1)%2] = (id185x_1);
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id346out_output;

  { // Node ID: 346 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id346in_input = id185out_result[getCycle()%2];

    id346out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>((cast_fixed2bits(id346in_input))));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id347out_o;

  { // Node ID: 347 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id347in_i = id346out_output;

    id347out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id347in_i));
  }
  { // Node ID: 194 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id194in_a = id175out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id194in_b = id347out_o;

    id194out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id194in_a,id194in_b));
  }
  { // Node ID: 358 (NodeConstantRawBits)
  }
  { // Node ID: 204 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id204in_a = id65out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id204in_b = id358out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id204x_1;

    (id204x_1) = (and_fixed(id204in_a,id204in_b));
    id204out_result[(getCycle()+1)%2] = (id204x_1);
  }
  { // Node ID: 213 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id213in_a = id194out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id213in_b = id204out_result[getCycle()%2];

    id213out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id213in_a,id213in_b));
  }
  { // Node ID: 357 (NodeConstantRawBits)
  }
  { // Node ID: 223 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id223in_a = id71out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id223in_b = id357out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id223x_1;

    (id223x_1) = (and_fixed(id223in_a,id223in_b));
    id223out_result[(getCycle()+1)%2] = (id223x_1);
  }
  HWOffsetFix<32,1,TWOSCOMPLEMENT> id348out_output;

  { // Node ID: 348 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id348in_input = id223out_result[getCycle()%2];

    id348out_output = (cast_bits2fixed<32,1,TWOSCOMPLEMENT>((cast_fixed2bits(id348in_input))));
  }
  HWOffsetFix<32,0,TWOSCOMPLEMENT> id349out_o;

  { // Node ID: 349 (NodeCast)
    const HWOffsetFix<32,1,TWOSCOMPLEMENT> &id349in_i = id348out_output;

    id349out_o = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id349in_i));
  }
  { // Node ID: 232 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id232in_a = id213out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id232in_b = id349out_o;

    id232out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id232in_a,id232in_b));
  }
  { // Node ID: 356 (NodeConstantRawBits)
  }
  { // Node ID: 242 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id242in_a = id77out_output[getCycle()%4];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id242in_b = id356out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id242x_1;

    (id242x_1) = (and_fixed(id242in_a,id242in_b));
    id242out_result[(getCycle()+1)%2] = (id242x_1);
  }
  { // Node ID: 251 (NodeAdd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id251in_a = id232out_result[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id251in_b = id242out_result[getCycle()%2];

    id251out_result[(getCycle()+1)%2] = (add_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id251in_a,id251in_b));
  }
  HWOffsetFix<32,-4,TWOSCOMPLEMENT> id350out_output;

  { // Node ID: 350 (NodeReinterpret)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id350in_input = id251out_result[getCycle()%2];

    id350out_output = (cast_bits2fixed<32,-4,TWOSCOMPLEMENT>((cast_fixed2bits(id350in_input))));
  }
  { // Node ID: 351 (NodeCast)
    const HWOffsetFix<32,-4,TWOSCOMPLEMENT> &id351in_i = id350out_output;

    id351out_o[(getCycle()+1)%2] = (cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(id351in_i));
  }
  { // Node ID: 355 (NodeConstantRawBits)
  }
  { // Node ID: 268 (NodeAnd)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id268in_a = id351out_o[getCycle()%2];
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id268in_b = id355out_value;

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id268x_1;

    (id268x_1) = (and_fixed(id268in_a,id268in_b));
    id268out_result[(getCycle()+1)%2] = (id268x_1);
  }
  { // Node ID: 390 (NodeFIFO)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id390in_input = id268out_result[getCycle()%2];

    id390out_output[(getCycle()+1)%2] = id390in_input;
  }
  { // Node ID: 269 (NodeOr)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id269in_a = id266out_output;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id269in_b = id390out_output[getCycle()%2];

    HWOffsetFix<32,0,TWOSCOMPLEMENT> id269x_1;

    (id269x_1) = (or_fixed(id269in_a,id269in_b));
    id269out_result[(getCycle()+1)%2] = (id269x_1);
  }
  if ( (getFillLevel() >= (26l)) && (getFlushLevel() < (26l)|| !isFlushingActive() ))
  { // Node ID: 274 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id274in_output_control = id272out_result;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id274in_data = id269out_result[getCycle()%2];

    bool id274x_1;

    (id274x_1) = ((id274in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(26l))&(isFlushingActive()))));
    if((id274x_1)) {
      writeOutput(m_y, id274in_data);
    }
  }
  { // Node ID: 279 (NodeConstantRawBits)
  }
  { // Node ID: 354 (NodeConstantRawBits)
  }
  { // Node ID: 276 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 277 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id277in_enable = id354out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id277in_max = id276out_value;

    HWOffsetFix<49,0,UNSIGNED> id277x_1;
    HWOffsetFix<1,0,UNSIGNED> id277x_2;
    HWOffsetFix<1,0,UNSIGNED> id277x_3;
    HWOffsetFix<49,0,UNSIGNED> id277x_4t_1e_1;

    id277out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id277st_count)));
    (id277x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id277st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id277x_2) = (gte_fixed((id277x_1),id277in_max));
    (id277x_3) = (and_fixed((id277x_2),id277in_enable));
    id277out_wrap = (id277x_3);
    if((id277in_enable.getValueAsBool())) {
      if(((id277x_3).getValueAsBool())) {
        (id277st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id277x_4t_1e_1) = (id277x_1);
        (id277st_count) = (id277x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id278out_output;

  { // Node ID: 278 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id278in_input = id277out_count;

    id278out_output = id278in_input;
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 280 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id280in_load = id279out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id280in_data = id278out_output;

    bool id280x_1;

    (id280x_1) = ((id280in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id280x_1)) {
      setMappedRegValue("current_run_cycle_count", id280in_data);
    }
  }
  { // Node ID: 353 (NodeConstantRawBits)
  }
  { // Node ID: 282 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 283 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id283in_enable = id353out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id283in_max = id282out_value;

    HWOffsetFix<49,0,UNSIGNED> id283x_1;
    HWOffsetFix<1,0,UNSIGNED> id283x_2;
    HWOffsetFix<1,0,UNSIGNED> id283x_3;
    HWOffsetFix<49,0,UNSIGNED> id283x_4t_1e_1;

    id283out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id283st_count)));
    (id283x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id283st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id283x_2) = (gte_fixed((id283x_1),id283in_max));
    (id283x_3) = (and_fixed((id283x_2),id283in_enable));
    id283out_wrap = (id283x_3);
    if((id283in_enable.getValueAsBool())) {
      if(((id283x_3).getValueAsBool())) {
        (id283st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id283x_4t_1e_1) = (id283x_1);
        (id283st_count) = (id283x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 285 (NodeInputMappedReg)
  }
  { // Node ID: 352 (NodeEqInlined)
    const HWOffsetFix<48,0,UNSIGNED> &id352in_a = id283out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id352in_b = id285out_run_cycle_count;

    id352out_result[(getCycle()+1)%2] = (eq_fixed(id352in_a,id352in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 284 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id284in_start = id352out_result[getCycle()%2];

    if((id284in_start.getValueAsBool())) {
      startFlushing();
    }
  }
  { // Node ID: 4 (NodeInputMappedReg)
  }
};

};
