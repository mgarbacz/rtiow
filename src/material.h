#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"
#include "hittable.h"
#include "ray.h"

class hit_record;

class material {
  public:
    virtual ~material() = default;

    virtual bool scatter(const ray& r_in,
                         const hit_record& rec,
                         color& attenuation,
                         ray& scattered) const = 0;
};

class lambertian : public material {
  public:
    lambertian(const color& a) : albedo(a) {}

    bool scatter(const ray& r_in,
                 const hit_record& rec,
                 color& attenuation,
                 ray& scattered) const override {
      auto scatter_direction = rec.normal + random_unit_vector();
      scattered = ray(rec.p, scatter_direction);
      attenuation = albedo;
      return true;
    }
  
  private:
    color albedo;
};

#endif