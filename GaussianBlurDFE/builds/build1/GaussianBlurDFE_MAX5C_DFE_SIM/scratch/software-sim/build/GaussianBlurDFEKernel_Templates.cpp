#include "stdsimheader.h"

using namespace maxcompilersim;

namespace maxcompilersim {
// Templated Types used in the kernel
template class HWRawBits<32>;
template class HWOffsetFix<48,0,UNSIGNED>;
template class HWOffsetFix<49,0,UNSIGNED>;
template class HWOffsetFix<32,1,TWOSCOMPLEMENT>;
template class HWOffsetFix<32,0,TWOSCOMPLEMENT>;
template class HWOffsetFix<32,-4,TWOSCOMPLEMENT>;
template class HWOffsetFix<1,0,UNSIGNED>;
template class HWOffsetFix<32,2,TWOSCOMPLEMENT>;
// add. templates from the default formatter 


// Templated Methods/Functions
template HWOffsetFix<32,0,TWOSCOMPLEMENT>or_fixed<>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &b );
template HWOffsetFix<32,0,TWOSCOMPLEMENT> cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<32,1,TWOSCOMPLEMENT> &a);
template HWRawBits<32> cast_fixed2bits<>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a);
template HWOffsetFix<1,0,UNSIGNED>not_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a );
template HWOffsetFix<32,2,TWOSCOMPLEMENT> cast_bits2fixed<32,2,TWOSCOMPLEMENT>(const HWRawBits<32> &a);
template HWOffsetFix<32,0,TWOSCOMPLEMENT>add_fixed <32,0,TWOSCOMPLEMENT,TONEAREVEN,32,0,TWOSCOMPLEMENT,32,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<48,0,UNSIGNED> &a, const HWOffsetFix<48,0,UNSIGNED> &b );
template void KernelManagerBlockSync::writeOutput< HWOffsetFix<32,0,TWOSCOMPLEMENT> >(const t_port_number port_number, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &value);
template HWOffsetFix<1,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<1,0,UNSIGNED> >(const std::string &name);
template HWOffsetFix<48,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name);
template HWOffsetFix<32,0,TWOSCOMPLEMENT>sub_fixed <32,0,TWOSCOMPLEMENT,TONEAREVEN,32,0,TWOSCOMPLEMENT,32,0,TWOSCOMPLEMENT, false>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &b , EXCEPTOVERFLOW);
template HWOffsetFix<32,0,TWOSCOMPLEMENT>and_fixed<>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a, const HWOffsetFix<32,0,TWOSCOMPLEMENT> &b );
template void KernelManagerBlockSync::setMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name, const HWOffsetFix<48,0,UNSIGNED> & value);
template HWOffsetFix<32,1,TWOSCOMPLEMENT> cast_bits2fixed<32,1,TWOSCOMPLEMENT>(const HWRawBits<32> &a);
template HWRawBits<32>shift_left_fixed<>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a, long shift_by );
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b );
template HWOffsetFix<32,0,TWOSCOMPLEMENT>neg_fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a );
template HWOffsetFix<32,0,TWOSCOMPLEMENT> cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<32,2,TWOSCOMPLEMENT> &a);
template HWOffsetFix<48,0,UNSIGNED> cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<49,0,UNSIGNED> &a);
template HWOffsetFix<32,0,TWOSCOMPLEMENT> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<32,0,TWOSCOMPLEMENT> >(const std::string &name);
template HWOffsetFix<32,-4,TWOSCOMPLEMENT> cast_bits2fixed<32,-4,TWOSCOMPLEMENT>(const HWRawBits<32> &a);
template HWOffsetFix<49,0,UNSIGNED>add_fixed <49,0,UNSIGNED,TRUNCATE,49,0,UNSIGNED,49,0,UNSIGNED, false>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<32,0,TWOSCOMPLEMENT> cast_bits2fixed<32,0,TWOSCOMPLEMENT>(const HWRawBits<32> &a);
template HWRawBits<32>shift_right_fixed<>(const HWOffsetFix<32,0,TWOSCOMPLEMENT> &a, long shift_by );
template HWOffsetFix<32,0,TWOSCOMPLEMENT> cast_fixed2fixed<32,0,TWOSCOMPLEMENT,TONEAREVEN>(const HWOffsetFix<32,-4,TWOSCOMPLEMENT> &a);
template HWOffsetFix<32,0,TWOSCOMPLEMENT> KernelManagerBlockSync::readInput< HWOffsetFix<32,0,TWOSCOMPLEMENT> >(const t_port_number port_number);
template HWOffsetFix<1,0,UNSIGNED>and_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<1,0,UNSIGNED> &b );


// Additional Code

} // End of maxcompilersim namespace
