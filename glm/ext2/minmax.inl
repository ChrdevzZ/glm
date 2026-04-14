/// @ref ext2_minmax

#if GLM_HAS_CXX11_STL
#   include <algorithm> // for std::minmax
#endif


namespace glm
{

	// minmax
#	if GLM_HAS_CXX11_STL
		template<typename genType>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y)
		{
			return std::minmax<typename std::decay<genType>::type>(x, y);
		}

		template<typename genType>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y, genType z)
		{
			return std::minmax<typename std::decay<genType>::type>({ x, y, z });
		}

		template<typename genType>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y, genType z, genType w)
		{
			return std::minmax<typename std::decay<genType>::type>({ x, y, z, w });
		}
#   else
		template<typename genType>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y)
		{
			static_assert(std::numeric_limits<genType>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT || std::numeric_limits<genType>::is_integer, "'minmax' only accept floating-point or integer inputs");
			return (y < x) ? std::pair<genType, genType>(y, x) : std::pair<genType, genType>(x, y);
		}

		template<typename genType>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y, genType z)
		{
			static_assert(std::numeric_limits<genType>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT || std::numeric_limits<genType>::is_integer, "'minmax' only accept floating-point or integer inputs");
			std::pair<genType, genType> const range = glm::minmax(x, y);
			return std::pair<genType, genType>(glm::min(range.first, z), glm::max(range.second, z));
		}

		template<typename genType>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<genType, genType> minmax(genType x, genType y, genType z, genType w)
		{
			static_assert(std::numeric_limits<genType>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT || std::numeric_limits<genType>::is_integer, "'minmax' only accept floating-point or integer inputs");
			std::pair<genType, genType> const range0 = glm::minmax(x, y);
			std::pair<genType, genType> const range1 = glm::minmax(z, w);
			return std::pair<genType, genType>(glm::min(range0.first, range1.first), glm::max(range0.second, range1.second));
		}
#   endif

}//namespace glm


namespace glm{
namespace detail
{

	template<typename T>
	struct TMinmax
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<T, T> operator()(T const& a, T const& b) const
		{
			return glm::minmax(a, b);
		}

		GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<T, T> operator()(T const& a, T const& b, T const& c) const
		{
			return glm::minmax(a, b, c);
		}

		GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<T, T> operator()(T const& a, T const& b, T const& c, T const& d) const
		{
			return glm::minmax(a, b, c, d);
		}
	};

	template<length_t L, typename T, qualifier Q>
	struct compute_minmax_vector_pair2;

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair2<1, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<1, T, Q>, vec<1, T, Q>> call(Fct func, vec<1, T, Q> const& a, vec<1, T, Q> const& b)
		{
			std::pair<T, T> const r0 = func(a.x, b.x);
			return std::pair<vec<1, T, Q>, vec<1, T, Q>>(vec<1, T, Q>(r0.first), vec<1, T, Q>(r0.second));
		}
	};

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair2<2, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<2, T, Q>, vec<2, T, Q>> call(Fct func, vec<2, T, Q> const& a, vec<2, T, Q> const& b)
		{
			std::pair<T, T> const r0 = func(a.x, b.x);
			std::pair<T, T> const r1 = func(a.y, b.y);
			return std::pair<vec<2, T, Q>, vec<2, T, Q>>(vec<2, T, Q>(r0.first, r1.first), vec<2, T, Q>(r0.second, r1.second));
		}
	};

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair2<3, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<3, T, Q>, vec<3, T, Q>> call(Fct func, vec<3, T, Q> const& a, vec<3, T, Q> const& b)
		{
			std::pair<T, T> const r0 = func(a.x, b.x);
			std::pair<T, T> const r1 = func(a.y, b.y);
			std::pair<T, T> const r2 = func(a.z, b.z);
			return std::pair<vec<3, T, Q>, vec<3, T, Q>>(vec<3, T, Q>(r0.first, r1.first, r2.first), vec<3, T, Q>(r0.second, r1.second, r2.second));
		}
	};

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair2<4, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<4, T, Q>, vec<4, T, Q>> call(Fct func, vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			std::pair<T, T> const r0 = func(a.x, b.x);
			std::pair<T, T> const r1 = func(a.y, b.y);
			std::pair<T, T> const r2 = func(a.z, b.z);
			std::pair<T, T> const r3 = func(a.w, b.w);
			return std::pair<vec<4, T, Q>, vec<4, T, Q>>(vec<4, T, Q>(r0.first, r1.first, r2.first, r3.first), vec<4, T, Q>(r0.second, r1.second, r2.second, r3.second));
		}
	};

	template<length_t L, typename T, qualifier Q>
	struct compute_minmax_vector_pair3;

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair3<1, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<1, T, Q>, vec<1, T, Q>> call(Fct func, vec<1, T, Q> const& a, vec<1, T, Q> const& b, vec<1, T, Q> const& c)
		{
			std::pair<T, T> const r0 = func(a.x, b.x, c.x);
			return std::pair<vec<1, T, Q>, vec<1, T, Q>>(vec<1, T, Q>(r0.first), vec<1, T, Q>(r0.second));
		}
	};

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair3<2, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<2, T, Q>, vec<2, T, Q>> call(Fct func, vec<2, T, Q> const& a, vec<2, T, Q> const& b, vec<2, T, Q> const& c)
		{
			std::pair<T, T> const r0 = func(a.x, b.x, c.x);
			std::pair<T, T> const r1 = func(a.y, b.y, c.y);
			return std::pair<vec<2, T, Q>, vec<2, T, Q>>(vec<2, T, Q>(r0.first, r1.first), vec<2, T, Q>(r0.second, r1.second));
		}
	};

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair3<3, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<3, T, Q>, vec<3, T, Q>> call(Fct func, vec<3, T, Q> const& a, vec<3, T, Q> const& b, vec<3, T, Q> const& c)
		{
			std::pair<T, T> const r0 = func(a.x, b.x, c.x);
			std::pair<T, T> const r1 = func(a.y, b.y, c.y);
			std::pair<T, T> const r2 = func(a.z, b.z, c.z);
			return std::pair<vec<3, T, Q>, vec<3, T, Q>>(vec<3, T, Q>(r0.first, r1.first, r2.first), vec<3, T, Q>(r0.second, r1.second, r2.second));
		}
	};

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair3<4, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<4, T, Q>, vec<4, T, Q>> call(Fct func, vec<4, T, Q> const& a, vec<4, T, Q> const& b, vec<4, T, Q> const& c)
		{
			std::pair<T, T> const r0 = func(a.x, b.x, c.x);
			std::pair<T, T> const r1 = func(a.y, b.y, c.y);
			std::pair<T, T> const r2 = func(a.z, b.z, c.z);
			std::pair<T, T> const r3 = func(a.w, b.w, c.w);
			return std::pair<vec<4, T, Q>, vec<4, T, Q>>(vec<4, T, Q>(r0.first, r1.first, r2.first, r3.first), vec<4, T, Q>(r0.second, r1.second, r2.second, r3.second));
		}
	};

	template<length_t L, typename T, qualifier Q>
	struct compute_minmax_vector_pair4;

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair4<1, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<1, T, Q>, vec<1, T, Q>> call(Fct func, vec<1, T, Q> const& a, vec<1, T, Q> const& b, vec<1, T, Q> const& c, vec<1, T, Q> const& d)
		{
			std::pair<T, T> const r0 = func(a.x, b.x, c.x, d.x);
			return std::pair<vec<1, T, Q>, vec<1, T, Q>>(vec<1, T, Q>(r0.first), vec<1, T, Q>(r0.second));
		}
	};

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair4<2, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<2, T, Q>, vec<2, T, Q>> call(Fct func, vec<2, T, Q> const& a, vec<2, T, Q> const& b, vec<2, T, Q> const& c, vec<2, T, Q> const& d)
		{
			std::pair<T, T> const r0 = func(a.x, b.x, c.x, d.x);
			std::pair<T, T> const r1 = func(a.y, b.y, c.y, d.y);
			return std::pair<vec<2, T, Q>, vec<2, T, Q>>(vec<2, T, Q>(r0.first, r1.first), vec<2, T, Q>(r0.second, r1.second));
		}
	};

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair4<3, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<3, T, Q>, vec<3, T, Q>> call(Fct func, vec<3, T, Q> const& a, vec<3, T, Q> const& b, vec<3, T, Q> const& c, vec<3, T, Q> const& d)
		{
			std::pair<T, T> const r0 = func(a.x, b.x, c.x, d.x);
			std::pair<T, T> const r1 = func(a.y, b.y, c.y, d.y);
			std::pair<T, T> const r2 = func(a.z, b.z, c.z, d.z);
			return std::pair<vec<3, T, Q>, vec<3, T, Q>>(vec<3, T, Q>(r0.first, r1.first, r2.first), vec<3, T, Q>(r0.second, r1.second, r2.second));
		}
	};

	template<typename T, qualifier Q>
	struct compute_minmax_vector_pair4<4, T, Q>
	{
		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<4, T, Q>, vec<4, T, Q>> call(Fct func, vec<4, T, Q> const& a, vec<4, T, Q> const& b, vec<4, T, Q> const& c, vec<4, T, Q> const& d)
		{
			std::pair<T, T> const r0 = func(a.x, b.x, c.x, d.x);
			std::pair<T, T> const r1 = func(a.y, b.y, c.y, d.y);
			std::pair<T, T> const r2 = func(a.z, b.z, c.z, d.z);
			std::pair<T, T> const r3 = func(a.w, b.w, c.w, d.w);
			return std::pair<vec<4, T, Q>, vec<4, T, Q>>(vec<4, T, Q>(r0.first, r1.first, r2.first, r3.first), vec<4, T, Q>(r0.second, r1.second, r2.second, r3.second));
		}
	};

	template<length_t L, typename T, qualifier Q, bool Aligned>
	struct compute_minmax_vector
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<L, T, Q>, vec<L, T, Q>> call(vec<L, T, Q> const& x, vec<L, T, Q> const& y)
		{
			return compute_minmax_vector_pair2<L, T, Q>::call(TMinmax<T>(), x, y);
		}

		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<L, T, Q>, vec<L, T, Q>> call(vec<L, T, Q> const& x, vec<L, T, Q> const& y, vec<L, T, Q> const& z)
		{
			return compute_minmax_vector_pair3<L, T, Q>::call(TMinmax<T>(), x, y, z);
		}

		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static std::pair<vec<L, T, Q>, vec<L, T, Q>> call(vec<L, T, Q> const& x, vec<L, T, Q> const& y, vec<L, T, Q> const& z, vec<L, T, Q> const& w)
		{
			return compute_minmax_vector_pair4<L, T, Q>::call(TMinmax<T>(), x, y, z, w);
		}
	};

}//namespace detail

	// minmax
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& a, T b)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT || std::numeric_limits<T>::is_integer, "'minmax' only accept floating-point or integer inputs");
		return detail::compute_minmax_vector<L, T, Q, detail::is_aligned<Q>::value>::call(a, vec<L, T, Q>(b));
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(T a, vec<L, T, Q> const& b)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT || std::numeric_limits<T>::is_integer, "'minmax' only accept floating-point or integer inputs");
		return detail::compute_minmax_vector<L, T, Q, detail::is_aligned<Q>::value>::call(vec<L, T, Q>(a), b);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& a, vec<L, T, Q> const& b)
	{
		return detail::compute_minmax_vector<L, T, Q, detail::is_aligned<Q>::value>::call(a, b);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& a, vec<L, T, Q> const& b, vec<L, T, Q> const& c)
	{
		return detail::compute_minmax_vector<L, T, Q, detail::is_aligned<Q>::value>::call(a, b, c);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::pair<vec<L, T, Q>, vec<L, T, Q>> minmax(vec<L, T, Q> const& a, vec<L, T, Q> const& b, vec<L, T, Q> const& c, vec<L, T, Q> const& d)
	{
		return detail::compute_minmax_vector<L, T, Q, detail::is_aligned<Q>::value>::call(a, b, c, d);
	}

}//namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "minmax_simd.inl"
#endif
