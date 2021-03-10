#define ALL __inline__ __host__ __device__

template <typename EdgeValue>
class Edge {
  public:
    ALL Edge(int id, int value) {
        vertexId = id;
        edgeValue = value;
    }
    ALL int getVertexId() { return vertexId; }
    ALL EdgeValue getValue() { return edgeValue; }
    ALL void setValue(EdgeValue x) { edgeValue = x; }

  private:
    EdgeValue edgeValue;
    int vertexId;
};

template <typename VertexValue, typename EdgeValue>
class ChiVertex {
  public:
    // init functions
    ALL ChiVertex(int id, int inDegree, int outDegree) {
        this->id = id;
        nInedges = inDegree;
        nOutedges = outDegree;
        inEdgeDataArray = (Edge<EdgeValue>**)malloc(
            sizeof(Edge<EdgeValue>*) * inDegree);
        outEdgeDataArray = (Edge<EdgeValue>**)malloc(
            sizeof(Edge<EdgeValue>*) * outDegree);
    }
    // operation functions
    ALL int getId() { return id; }
    ALL void setId(int x) { id = x; }
    ALL VertexValue getValue() { return value; }
    ALL void setValue(VertexValue x) { value = x; }
    ALL int numInEdges() { return nInedges; }
    ALL int numOutEdges() { return nOutedges; }
    ALL Edge<EdgeValue>* getInEdge(int i) { return inEdgeDataArray[i]; }
    ALL Edge<EdgeValue>* getOutEdge(int i) { return outEdgeDataArray[i]; }
    ALL void setInEdge(int idx, int vertexId, EdgeValue value) {
        inEdgeDataArray[idx] = new Edge<EdgeValue>(vertexId, value);
    }
    ALL void setOutEdge(ChiVertex<float, float>** vertex, int src, int idx,
                        int vertexId, EdgeValue value) {
        // outEdgeDataArray[idx] = new Edge<EdgeValue>(vertexId, value);
        for (int i = 0; i < vertex[vertexId]->numInEdges(); i++) {
            if (vertex[vertexId]->getInEdge(i)->getVertexId() == src) {
                outEdgeDataArray[idx] = vertex[vertexId]->getInEdge(i);
                break;
            }
        }
    }

  private:
    int id;
    int nInedges;
    int nOutedges;
    VertexValue value;
    Edge<EdgeValue>** inEdgeDataArray;
    Edge<EdgeValue>** outEdgeDataArray;
};

class GraphChiContext {
  public:
    ALL GraphChiContext(int vert) {}
    ALL int getNumIterations() { return numIterations; }

    ALL void setNumIterations(int iter) { numIterations = iter; }
    ALL int getNumVertices() { return numVertices; }

    ALL void setNumVertices(int vertices) { numVertices = vertices; }
    ALL int getNumEdges() { return numEdges; }

    ALL void setNumEdges(int edges) { numEdges = edges; }

  private:
    int numIterations;
    int numVertices;
    int numEdges;
};
