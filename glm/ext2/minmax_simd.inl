#include "../simd/common.h"

namespace glm{
namespace detail
{
#if GLM_ARCH & GLM_ARCH_SSE2_BIT
#  if GLM_CONFIG_ALIGNED_GENTYPES == GLM_ENABLE

	template<qualifier Q>
	struct compute_minmax_vector<3, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static std::pair<vec<3, float, Q>, vec<3, float, Q>> call(vec<3, float, Q> const& x, vec<3, float, Q> const& y)
		{
			vec<3, float, Q> low;
			vec<3, float, Q> high;
			low.data = _mm_min_ps(x.data, y.data);
			high.data = _mm_max_ps(x.data, y.data);
			return std::pair<vec<3, float, Q>, vec<3, float, Q>>(low, high);
		}

		GLM_FUNC_QUALIFIER static std::pair<vec<3, float, Q>, vec<3, float, Q>> call(vec<3, float, Q> const& x, vec<3, float, Q> const& y, vec<3, float, Q> const& z)
		{
			vec<3, float, Q> low;
			vec<3, float, Q> high;
			glm_f32vec4 const low0 = _mm_min_ps(x.data, y.data);
			glm_f32vec4 const high0 = _mm_max_ps(x.data, y.data);
			low.data = _mm_min_ps(low0, z.data);
			high.data = _mm_max_ps(high0, z.data);
			return std::pair<vec<3, float, Q>, vec<3, float, Q>>(low, high);
		}

		GLM_FUNC_QUALIFIER static std::pair<vec<3, float, Q>, vec<3, float, Q>> call(vec<3, float, Q> const& x, vec<3, float, Q> const& y, vec<3, float, Q> const& z, vec<3, float, Q> const& w)
		{
			vec<3, float, Q> low;
			vec<3, float, Q> high;
			glm_f32vec4 const low0 = _mm_min_ps(x.data, y.data);
			glm_f32vec4 const low1 = _mm_min_ps(z.data, w.data);
			glm_f32vec4 const high0 = _mm_max_ps(x.data, y.data);
			glm_f32vec4 const high1 = _mm_max_ps(z.data, w.data);
			low.data = _mm_min_ps(low0, low1);
			high.data = _mm_max_ps(high0, high1);
			return std::pair<vec<3, float, Q>, vec<3, float, Q>>(low, high);
		}
	};

	template<qualifier Q>
	struct compute_minmax_vector<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static std::pair<vec<4, float, Q>, vec<4, float, Q>> call(vec<4, float, Q> const& x, vec<4, float, Q> const& y)
		{
			vec<4, float, Q> low;
			vec<4, float, Q> high;
			low.data = _mm_min_ps(x.data, y.data);
			high.data = _mm_max_ps(x.data, y.data);
			return std::pair<vec<4, float, Q>, vec<4, float, Q>>(low, high);
		}

		GLM_FUNC_QUALIFIER static std::pair<vec<4, float, Q>, vec<4, float, Q>> call(vec<4, float, Q> const& x, vec<4, float, Q> const& y, vec<4, float, Q> const& z)
		{
			vec<4, float, Q> low;
			vec<4, float, Q> high;
			glm_f32vec4 const low0 = _mm_min_ps(x.data, y.data);
			glm_f32vec4 const high0 = _mm_max_ps(x.data, y.data);
			low.data = _mm_min_ps(low0, z.data);
			high.data = _mm_max_ps(high0, z.data);
			return std::pair<vec<4, float, Q>, vec<4, float, Q>>(low, high);
		}

		GLM_FUNC_QUALIFIER static std::pair<vec<4, float, Q>, vec<4, float, Q>> call(vec<4, float, Q> const& x, vec<4, float, Q> const& y, vec<4, float, Q> const& z, vec<4, float, Q> const& w)
		{
			vec<4, float, Q> low;
			vec<4, float, Q> high;
			glm_f32vec4 const low0 = _mm_min_ps(x.data, y.data);
			glm_f32vec4 const low1 = _mm_min_ps(z.data, w.data);
			glm_f32vec4 const high0 = _mm_max_ps(x.data, y.data);
			glm_f32vec4 const high1 = _mm_max_ps(z.data, w.data);
			low.data = _mm_min_ps(low0, low1);
			high.data = _mm_max_ps(high0, high1);
			return std::pair<vec<4, float, Q>, vec<4, float, Q>>(low, high);
		}
	};

#  endif//GLM_CONFIG_ALIGNED_GENTYPES == GLM_ENABLE
#endif//GLM_ARCH & GLM_ARCH_SSE2_BIT
}//namespace detail
}//namespace glm
