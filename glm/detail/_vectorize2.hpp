#pragma once

namespace glm{
namespace detail
{
	template<template<length_t L, typename T, qualifier Q> class vec, length_t L, typename T, qualifier Q>
	struct functor3{};

	template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
	struct functor3<vec, 1, T, Q>
	{
		GLM_FUNC_QUALIFIER static vec<1, T, Q> call(T (*Func) (T x, T y), vec<1, T, Q> const& a, vec<1, T, Q> const& b, vec<1, T, Q> const& c)
		{
			return vec<1, T, Q>(Func(a.x, b.x, c.x));
		}

		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<1, T, Q> call(Fct Func, vec<1, T, Q> const& a, vec<1, T, Q> const& b, vec<1, T, Q> const& c)
		{
			return vec<1, T, Q>(Func(a.x, b.x, c.x));
		}
	};

	template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
	struct functor3<vec, 2, T, Q>
	{
		GLM_FUNC_QUALIFIER static vec<2, T, Q> call(T (*Func) (T x, T y), vec<2, T, Q> const& a, vec<2, T, Q> const& b, vec<2, T, Q> const& c)
		{
			return vec<2, T, Q>(Func(a.x, b.x, c.x), Func(a.y, b.y, c.y));
		}

		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<2, T, Q> call(Fct Func, vec<2, T, Q> const& a, vec<2, T, Q> const& b, vec<2, T, Q> const& c)
		{
			return vec<2, T, Q>(Func(a.x, b.x, c.x), Func(a.y, b.y, c.y));
		}
	};

	template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
	struct functor3<vec, 3, T, Q>
	{
		GLM_FUNC_QUALIFIER static vec<3, T, Q> call(T (*Func) (T x, T y), vec<3, T, Q> const& a, vec<3, T, Q> const& b, vec<3, T, Q> const& c)
		{
			return vec<3, T, Q>(Func(a.x, b.x, c.x), Func(a.y, b.y, c.y), Func(a.z, b.z, c.z));
		}

		template<class Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<3, T, Q> call(Fct Func, vec<3, T, Q> const& a, vec<3, T, Q> const& b, vec<3, T, Q> const& c)
		{
			return vec<3, T, Q>(Func(a.x, b.x, c.x), Func(a.y, b.y, c.y), Func(a.z, b.z, c.z));
		}
	};

	template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
	struct functor3<vec, 4, T, Q>
	{
		GLM_FUNC_QUALIFIER static vec<4, T, Q> call(T (*Func) (T x, T y), vec<4, T, Q> const& a, vec<4, T, Q> const& b, vec<4, T, Q> const& c)
		{
			return vec<4, T, Q>(Func(a.x, b.x, c.x), Func(a.y, b.y, c.y), Func(a.z, b.z, c.z), Func(a.w, b.w, c.w));
		}

		template<class Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T, Q> call(Fct Func, vec<4, T, Q> const& a, vec<4, T, Q> const& b, vec<4, T, Q> const& c)
		{
			return vec<4, T, Q>(Func(a.x, b.x, c.x), Func(a.y, b.y, c.y), Func(a.z, b.z, c.z), Func(a.w, b.w, c.w));
		}
	};

	template<template<length_t L, typename T, qualifier Q> class vec, length_t L, typename T, qualifier Q>
	struct functor4{};

	template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
	struct functor4<vec, 1, T, Q>
	{
		GLM_FUNC_QUALIFIER static vec<1, T, Q> call(T (*Func) (T x, T y), vec<1, T, Q> const& a, vec<1, T, Q> const& b, vec<1, T, Q> const& c, vec<1, T, Q> const& d)
		{
			return vec<1, T, Q>(Func(a.x, b.x, c.x, d.x));
		}

		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<1, T, Q> call(Fct Func, vec<1, T, Q> const& a, vec<1, T, Q> const& b, vec<1, T, Q> const& c, vec<1, T, Q> const& d)
		{
			return vec<1, T, Q>(Func(a.x, b.x, c.x, d.x));
		}
	};

	template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
	struct functor4<vec, 2, T, Q>
	{
		GLM_FUNC_QUALIFIER static vec<2, T, Q> call(T (*Func) (T x, T y), vec<2, T, Q> const& a, vec<2, T, Q> const& b, vec<2, T, Q> const& c, vec<2, T, Q> const& d)
		{
			return vec<2, T, Q>(Func(a.x, b.x, c.x, d.x), Func(a.y, b.y, c.y, d.y));
		}

		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<2, T, Q> call(Fct Func, vec<2, T, Q> const& a, vec<2, T, Q> const& b, vec<2, T, Q> const& c, vec<2, T, Q> const& d)
		{
			return vec<2, T, Q>(Func(a.x, b.x, c.x, d.x), Func(a.y, b.y, c.y, d.y));
		}
	};

	template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
	struct functor4<vec, 3, T, Q>
	{
		GLM_FUNC_QUALIFIER static vec<3, T, Q> call(T (*Func) (T x, T y), vec<3, T, Q> const& a, vec<3, T, Q> const& b, vec<3, T, Q> const& c, vec<3, T, Q> const& d)
		{
			return vec<3, T, Q>(Func(a.x, b.x, c.x, d.x), Func(a.y, b.y, c.y, d.y), Func(a.z, b.z, c.z, d.z));
		}

		template<class Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<3, T, Q> call(Fct Func, vec<3, T, Q> const& a, vec<3, T, Q> const& b, vec<3, T, Q> const& c, vec<3, T, Q> const& d)
		{
			return vec<3, T, Q>(Func(a.x, b.x, c.x, d.x), Func(a.y, b.y, c.y, d.y), Func(a.z, b.z, c.z, d.z));
		}
	};

	template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
	struct functor4<vec, 4, T, Q>
	{
		GLM_FUNC_QUALIFIER static vec<4, T, Q> call(T (*Func) (T x, T y), vec<4, T, Q> const& a, vec<4, T, Q> const& b, vec<4, T, Q> const& c, vec<4, T, Q> const& d)
		{
			return vec<4, T, Q>(Func(a.x, b.x, c.x, d.x), Func(a.y, b.y, c.y, d.y), Func(a.z, b.z, c.z, d.z), Func(a.w, b.w, c.w, d.w));
		}

		template<class Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<4, T, Q> call(Fct Func, vec<4, T, Q> const& a, vec<4, T, Q> const& b, vec<4, T, Q> const& c, vec<4, T, Q> const& d)
		{
			return vec<4, T, Q>(Func(a.x, b.x, c.x, d.x), Func(a.y, b.y, c.y, d.y), Func(a.z, b.z, c.z, d.z), Func(a.w, b.w, c.w, d.w));
		}
	};
}//namespace detail
}//namespace glm
