#ifndef MESHBUILDER_H
#define MESHBUILDER_H
#include "mesh.h"
#include <QString>
#include "vector2d.h"

/**
 * @brief The MeshBuilder class, contains methods to create and load meshes
 */
class MeshBuilder
{
public:
    /**
     * Empty MeshBuilder constructor
     */
    MeshBuilder();

    /**
     * Loads a mesh for a file
     * @param[in] nom The file location to load from
     * @return The constructed mesh
     */
    Mesh loadMesh(const QString& nom) const;

    /**
     * Saves the mesh to a file
     * @param[in] nom The file location to save in
     * @param[in] mesh The mesh to save
     */
    void saveMesh(const QString& nom, const Mesh &mesh) const;

    /**
     * Destructor of MeshBuilder, empty.
     */
    ~MeshBuilder();
};
#endif // MESHBUILDER_H
