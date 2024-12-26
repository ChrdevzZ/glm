#include "../simd/common.h"

namespace glm{
namespace detail
{
#if GLM_ARCH & GLM_ARCH_SSE2_BIT
#  if GLM_CONFIG_ALIGNED_GENTYPES == GLM_ENABLE

	template<>
	struct compute_reciprocal<4, float, aligned_lowp, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, aligned_lowp> call(vec<4, float, aligned_lowp> const& v)
		{
			vec<4, float, aligned_lowp> Result;
			Result.data = glm_vec4_rcp_lowp(v.data);
			return Result;
		}
	};
	
	template<>
	struct compute_reciprocal<2, float, aligned_lowp, true>
	{
		GLM_FUNC_QUALIFIER static vec<2, float, aligned_lowp> call(vec<2, float, aligned_lowp> const& v)
		{
			auto Tmp = vec<4, float, aligned_lowp>(v.xyyy);
			Tmp.data = glm_vec4_rcp_lowp(Tmp.data);
			return Tmp.xy;
		}
	};
	
	template<>
	struct compute_reciprocal<1, float, aligned_lowp, true>
	{
		GLM_FUNC_QUALIFIER static vec<1, float, aligned_lowp> call(vec<1, float, aligned_lowp> const& v)
		{
			vec<4, float, aligned_lowp> Tmp(v);
			Tmp.data = glm_vec1_rcp_lowp(Tmp.data);
			return Tmp;
		}
	};

#  endif//GLM_CONFIG_ALIGNED_GENTYPES == GLM_ENABLE
#endif//GLM_ARCH & GLM_ARCH_SSE2_BIT
}//namespace detail
}//namespace glm
