#pragma once
#include <vector>
#include "..\elm\elm.hpp"
class Mesh3D
{
public:
	Mesh3D();
	~Mesh3D();

	bool loadMesh(const char *filePath);

	const int getNumVertices() { return numVertices; }
	const int getNumIndices() { return numIndices; }
	const std::vector<elm::vec3> getVertices() { return vertices; }
	const std::vector<elm::vec3> getNormals() { return normals; }
	const std::vector<elm::vec3> getTexCoords() { return texCoords; }
	const std::vector<unsigned int> getIndices() { return indices; }

	void setVertexBufferID(int index) { vertexBufferID = index; }
	void setNormalBufferID(int index) { normalBufferID = index; }
	void setTexCoordBufferID(int index) { texCoordBufferID = index; }
	void setIndexBufferID(int index) { indexBufferID = index; }

	int getVertexBufferID() { return vertexBufferID; }
	int getNormalBufferID() { return normalBufferID; }
	int getTexCoordBufferID() { return texCoordBufferID; }
	int getIndexBufferID() { return indexBufferID; }

	std::string getTexDiffusePath() { return texDiffusePath; }
	int getTexDiffuseID() { return texDiffuseID; }
	void setTexDiffuseID(int id) { texDiffuseID = id; }
	
private:
	int vertexBufferID;
	int normalBufferID;
	int texCoordBufferID;
	int indexBufferID;

	int numVertices;
	int numIndices;

	std::vector<elm::vec3> vertices;
	std::vector<elm::vec3> normals;
	std::vector<elm::vec3> texCoords;
	std::vector<unsigned int> indices;

	std::string texDiffusePath;

	int texDiffuseID;
	// store all raw mesh data here?
	// load the mesh here or from outside??
	// start with here and then move it out...

};