import networkx as nx
import matplotlib.pyplot as plt
import pandas as pd
from fpdf import FPDF
import os

def load_graph(file_path):
    """Načte neorientovaný graf ze souboru."""
    G = nx.Graph()
    with open(file_path, 'r') as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) >= 2:
                u, v = int(parts[0]), int(parts[1])
                weight = float(parts[2]) if len(parts) > 2 else 1.0
                G.add_edge(u, v, weight=weight)
    return G

def plot_degree_distribution(G, title, filename):
    """Vykreslí distribuci stupňů vrcholů."""
    degrees = [d for _, d in G.degree()]
    plt.figure()
    plt.hist(degrees, bins=50, alpha=0.75)
    plt.xlabel("Degree")
    plt.ylabel("Frequency")
    plt.title(title)
    plt.savefig(filename)
    plt.close()

def plot_graph(G, title, filename):
    """Vykreslí síťový graf."""
    plt.figure(figsize=(10, 7))
    pos = nx.spring_layout(G, seed=42)
    nx.draw(G, pos, node_size=20, edge_color='gray', alpha=0.7)
    plt.title(title)
    plt.savefig(filename)
    plt.close()

def generate_pdf_report(graph_stats, image_files, filename):
    """Vytvoří PDF report s výsledky analýzy."""
    pdf = FPDF()
    pdf.set_auto_page_break(auto=True, margin=15)
    pdf.add_page()
    pdf.set_font("Arial", style='', size=12)
    pdf.cell(200, 10, "Graph Analysis Report", ln=True, align='C')
    pdf.ln(10)
    
    for section, stats in graph_stats.items():
        pdf.set_font("Arial", style='B', size=12)
        pdf.cell(200, 10, section, ln=True)
        pdf.set_font("Arial", style='', size=10)
        for key, value in stats.items():
            pdf.cell(200, 8, f"{key}: {value}", ln=True)
        pdf.ln(5)
        
    for image in image_files:
        pdf.image(image, x=10, w=180)
        pdf.ln(10)
    
    pdf.output(filename)

def analyze_graph(G, name):
    """Analyzuje graf a vrací statistiky."""
    num_nodes = G.number_of_nodes()
    num_edges = G.number_of_edges()
    avg_degree = sum(dict(G.degree()).values()) / num_nodes if num_nodes > 0 else 0
    clustering = nx.average_clustering(G) if not isinstance(G, nx.MultiGraph) else 0
    hubs = sorted(G.degree(), key=lambda x: x[1], reverse=True)[:10]
    
    return {
        "Graph Name": name,
        "Number of Nodes": num_nodes,
        "Number of Edges": num_edges,
        "Average Degree": avg_degree,
        "Clustering Coefficient": clustering,
        "Top Hubs": hubs
    }

def main():
    bio_graph = load_graph("bio_graph.txt")
    temporal_graph = load_graph("temporal_graph.txt")
    
    bio_stats = analyze_graph(bio_graph, "Biological Network")
    temporal_stats = analyze_graph(temporal_graph, "Temporal Network")
    
    plot_degree_distribution(bio_graph, "Biological Network Degree Distribution", "bio_degree_dist.png")
    plot_degree_distribution(temporal_graph, "Temporal Network Degree Distribution", "temporal_degree_dist.png")
    plot_graph(bio_graph, "Biological Network Graph", "bio_network.png")
    plot_graph(temporal_graph, "Temporal Network Graph", "temporal_network.png")
    
    generate_pdf_report(
        {"Biological Network": bio_stats},
        ["bio_degree_dist.png", "bio_network.png"],
        "bio_network_report.pdf"
    )
    generate_pdf_report(
        {"Temporal Network": temporal_stats},
        ["temporal_degree_dist.png", "temporal_network.png"],
        "temporal_network_report.pdf"
    )
    print("✅ PDF reports generated successfully!")

if __name__ == "__main__":
    main()

