import networkx as nx
import matplotlib.pyplot as plt
import os
from fpdf import FPDF

# Function to load metrics from a file
def load_metrics(file_path):
    if not os.path.exists(file_path):
        return {}
    metrics = {}
    with open(file_path, 'r') as f:
        for line in f:
            if line.startswith("#") or not line.strip():
                continue
            parts = line.strip().split(": ")
            if len(parts) != 2:
                continue
            key, value = parts
            metrics[key] = value
    return metrics

# Function to load node degrees from a file
def load_node_degrees(file_path):
    if not os.path.exists(file_path):
        return {}
    degrees = {}
    with open(file_path, 'r') as f:
        for line in f:
            if line.startswith("#") or not line.strip():
                continue
            parts = line.strip().split()
            if len(parts) < 2:
                continue
            try:
                node, degree = int(parts[0]), int(parts[1])
                degrees[node] = degree
            except ValueError:
                continue  # Ignore lines that can't be parsed
    return degrees

# Function to plot degree distribution
def plot_degree_distribution(degrees, filename):
    if not degrees:
        return
    plt.figure()
    plt.hist(list(degrees.values()), bins=50, alpha=0.75)
    plt.xlabel("Degree")
    plt.ylabel("Frequency")
    plt.title(f"{filename} Degree Distribution")
    plt.savefig(f"{filename}.png")
    plt.close()

# Function to generate a PDF report
def generate_pdf_report(graph_name, metrics, degrees, filename):
    pdf = FPDF()
    pdf.set_auto_page_break(auto=True, margin=15)
    pdf.add_page()
    pdf.set_font("Arial", style='', size=12)
    pdf.cell(200, 10, f"{graph_name} Analysis Report", ln=True, align='C')
    pdf.ln(10)

    pdf.set_font("Arial", style='B', size=12)
    pdf.cell(200, 10, "Graph Metrics", ln=True)
    pdf.set_font("Arial", style='', size=10)
    for key, value in metrics.items():
        pdf.cell(200, 8, f"{key}: {value}", ln=True)
    pdf.ln(10)

    image_path = f"{graph_name.replace(' ', '_')}_degree_distribution.png"
    if os.path.exists(image_path):
        pdf.image(image_path, x=10, w=180)
    else:
        pdf.cell(200, 8, "Degree distribution image not found.", ln=True)

    pdf.output(filename)

# Function to process snapshots
def process_snapshots(snapshot_dir):
    snapshot_reports = []
    for file in sorted(os.listdir(snapshot_dir)):
        if file.endswith("_metrics.txt"):
            snapshot_name = file.replace("_metrics.txt", "")
            snapshot_metrics = load_metrics(os.path.join(snapshot_dir, file))
            snapshot_degrees = load_node_degrees(os.path.join(snapshot_dir, snapshot_name + "_node_degrees.txt"))

            plot_degree_distribution(snapshot_degrees, snapshot_name)
            pdf_filename = os.path.join(snapshot_dir, f"{snapshot_name}.pdf")
            generate_pdf_report(snapshot_name, snapshot_metrics, snapshot_degrees, pdf_filename)
            snapshot_reports.append(pdf_filename)

    return snapshot_reports

# Main function
def main():
    bio_metrics = load_metrics("bio_metrics.txt")
    bio_degrees = load_node_degrees("bio_graph_node_degrees.txt")
    plot_degree_distribution(bio_degrees, "Biological_Network")
    generate_pdf_report("Biological Network", bio_metrics, bio_degrees, "bio_report.pdf")

    temporal_metrics = load_metrics("temporal_metrics.txt")
    temporal_degrees = load_node_degrees("temporal_graph_node_degrees.txt")
    plot_degree_distribution(temporal_degrees, "Temporal_Network")
    generate_pdf_report("Temporal Network", temporal_metrics, temporal_degrees, "temporal_report.pdf")

    snapshot_reports = process_snapshots("snapshots")
    print("✅ Generated reports:", ["bio_report.pdf", "temporal_report.pdf"] + snapshot_reports)

# Execute main function
if __name__ == "__main__":
    main()

